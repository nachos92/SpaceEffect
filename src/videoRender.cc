#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <cassert>
#include "oggetti.h"
#include "render.h"
#include <iostream>
using namespace std;

#define WIDTH 800
#define HEIGHT 640
#define FPS 30

#define MAXCOLPI 5
#define MAXMETEORE 7



/**
* @param ::Player
* Disegna la bitmap assegnata all'instanza di Player.
* 0.1 e 0.1 sono gli indici di scala (rispetto gli assi x e y).
*/
void disegnaPlayer(Player ship) {

  al_draw_scaled_rotated_bitmap(ship.sprite, 640/2, 480/2, ship.posX, ship.posY,
    0.1, 0.1, ship.angolo * 3.14159 /180,0);

}

/**Rappresenta a schermo le statistiche di gioco (vite rimaste, punteggio). */
void playerStat(Player ship, ALLEGRO_BITMAP *cuore, ALLEGRO_FONT *textFont) {

  al_draw_textf(textFont, al_map_rgb(255,255,255),WIDTH - 10, 10, ALLEGRO_ALIGN_RIGHT,"PUNTI: %i",ship.punteggio);

  if(ship.vita > 0)
    for(int i=1; i<=ship.vita; i++)
      al_draw_scaled_bitmap(cuore, 0,0, 800, 800, i*40, 10, 30, 30, 0);

}

/**Visualizza la schermata iniziale (titolo del gioco e comandi possibili. */
void schermataMenu(ALLEGRO_BITMAP *sfondoMenu,ALLEGRO_FONT *menuFont,ALLEGRO_FONT *font) {

  al_draw_scaled_bitmap(sfondoMenu, 0, 0, al_get_bitmap_width(sfondoMenu),al_get_bitmap_height(sfondoMenu),
    0,0,WIDTH,HEIGHT,0);

  al_draw_textf(menuFont, al_map_rgb(255,255,0), WIDTH/2, 100, ALLEGRO_ALIGN_CENTRE,"SPACE EFFECT");
  al_draw_textf(font, al_map_rgb(255,255,255), 10, HEIGHT-60, ALLEGRO_ALIGN_LEFT,"SPAZIO: Nuova Partita");
  al_draw_textf(font, al_map_rgb(255,255,255), 10, HEIGHT-30, ALLEGRO_ALIGN_LEFT,"ESC: Esci dal gioco");
}

/**Visualizza la schemata di pausa dal gioco (testo "pausa" e comandi possibili). */
void schermataPausa(ALLEGRO_FONT *gameoverFont, ALLEGRO_FONT *font) {

  al_draw_textf(gameoverFont, al_map_rgb(255,255,255),WIDTH/2 , HEIGHT/2 - 50,
    ALLEGRO_ALIGN_CENTRE,"PAUSA");
  al_draw_textf(font, al_map_rgb(255,255,255), 10, HEIGHT-60,
    ALLEGRO_ALIGN_LEFT,"SPAZIO: Abbandona partita");
  al_draw_textf(font, al_map_rgb(255,255,255), 10, HEIGHT-30,
    ALLEGRO_ALIGN_LEFT,"ESC: Riprendi partita");

}

/**Visualizza la schermata di fine gioco (testo "gameover", punteggio finale ottenuto,
* comandi possibili.
*/
void schermataGameover(ALLEGRO_BITMAP *sfondoGameover, ALLEGRO_FONT *gameoverFont, ALLEGRO_FONT *punteggioFont,ALLEGRO_FONT *font, const int punteggio) {

 al_draw_scaled_bitmap(sfondoGameover, 0, 0, al_get_bitmap_width(sfondoGameover),
  al_get_bitmap_height(sfondoGameover),0,0,WIDTH,HEIGHT,0);

  al_draw_textf(gameoverFont, al_map_rgb(255,255,0),WIDTH/2 , 70,
    ALLEGRO_ALIGN_CENTRE,"GAME OVER");
  al_draw_textf(punteggioFont, al_map_rgb(255,255,255),WIDTH/2 , HEIGHT/2 + 90,
    ALLEGRO_ALIGN_CENTRE,"PUNTEGGIO: %i",punteggio);
  al_draw_textf(font, al_map_rgb(255,255,255),WIDTH/2 , HEIGHT - 80,
    ALLEGRO_ALIGN_CENTRE,"SPAZIO: Torna al menù");
  al_draw_textf(font, al_map_rgb(255,255,255),WIDTH/2 , HEIGHT - 60,
    ALLEGRO_ALIGN_CENTRE,"ESC: Esci dal gioco");




}


/** Disegna ogni colpo attivo come un cerchio pieno di centro
* dato dal relativo posX e posY.
*/
void disegnaColpo(Colpo colpi[], int nmax) {

  for(int i=0; i<nmax; i++) {

    if(colpi[i].attivo == true)
      al_draw_filled_circle(colpi[i].posX,colpi[i].posY,3,al_map_rgb(255,255,255));
  }
}

/** Ogni meteora "in vita" è rappresentata mediante la relativa bitmap.
* Per facilitare la lettura, gli attributi degli elementi di tipo Meteora
* sono stati memorizzati in variabili invece di accedere alle struct ogni volta.
*/
void disegnaMeteore(Meteora meteora[], int nmax, ALLEGRO_BITMAP *iconaMeteora) {

  int raggio,bordo,width,height,posX,posY;
  double scala;

  for(int i=0; i<nmax; i++) {

    if(meteora[i].inVita == true) {

      raggio = meteora[i].raggio;
      bordo = meteora[i].bordo;
      width = al_get_bitmap_width(meteora[i].sprite);
      height = al_get_bitmap_height(meteora[i].sprite);
      scala = meteora[i].scala;
      posX = meteora[i].posX;
      posY = meteora[i].posY;

      al_draw_scaled_bitmap(meteora[i].sprite,0,0,width, height, posX-(raggio+bordo), posY - raggio,
			    (raggio*2 + bordo)*scala,(raggio*2)*scala,0);
    }
  }
}

