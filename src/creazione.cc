#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <cmath>
#include <cassert>
#include "oggetti.h"
#include "inizializzazione.h"
#include <iostream>
using namespace std;





/**Assegna i valori iniziali all'oggetto di tipo Player.
*/
void initPlayer(Player &ship) {

  ship.posX = WIDTH / 2;
  ship.posY = HEIGHT /2;
  ship.angolo = 0;

  ship.vita = 3;
  ship.vel = 10;
  ship.punteggio = 0;
}



/**Assegna i valori iniziali all'oggetto di tipo Colpo.
*/
void initColpi(Colpo colpi[],int nmax) {

  for(int i=0; i<nmax; i++) {

    colpi[i].vel = 15;
    colpi[i].attivo = false;
  }
}

/**Assegna parte dei valori iniziali agli elementi dell'array di oggetti Meteora.
*
*/
void initMeteore(Meteora meteora[], int nmax) {


  for(int i=0; i<nmax; i++) {
    meteora[i].inVita = false;
    meteora[i].raggio = 40;
    meteora[i].bordo = meteora[i].raggio - 10;
  }
}

/** Genera valori casuali per determinare l'assegnamento degli attributi delle
* istanze di tipo Meteora.
*/
void genRandomVal(int &vel, int &x, int &y, int &angolo, int &tipo) {

  //Valore casuale tra 5 e 10
  vel = rand() % 5 + 5;

  //Valore casuale tra 0 e 199
  x = rand() % 200;

  //Valore casuale tra 30 e (HEIGHT - 30)
  y = rand() % (HEIGHT - 60) + 30;

  //Valore casuale tra 30 e 150
  angolo = rand() % 121 + 30;

  //Usata per assegnare casualmente le sprite delle meteore
  //Valore casuale tra 0 e 99
  tipo = rand() % 100;

}


/** Assegnamento del tipo (e della relativa sprite e indice di scala),
* in base al valore di randomTipo, valore definito nella funzione ::genRandomVal .
*/
void assegnaTipo(Meteora &meteora, int randomTipo, ALLEGRO_BITMAP *icone[]) {

  if(randomTipo <= 33) {
    meteora.tipo = PICCOLA;
    meteora.sprite = icone[0];
    meteora.scala = 1;
  }
  else if (randomTipo > 33 && randomTipo <= 66) {
    meteora.tipo = MEDIA;
    meteora.sprite = icone[2];
    meteora.scala = 1.4;
  }
  else if (randomTipo >66) {
    meteora.tipo = GRANDE;
    meteora.sprite = icone[1];
    meteora.scala = 1.6;
  }
}



/** Assegnamento dell'angolo e del "lato" di spawn all'istanza di tipo Meteora.
*/
void assegnaPos_e_moto(Meteora &meteora, int randomX, int randomY, int randomVel, int randomAng) {

  if(randomX > 30) {
    meteora.posX = 0;
    meteora.degrees = randomAng;
  }
  else {
    meteora.posX = WIDTH;
    meteora.degrees = -randomAng;
  }

  meteora.posY = randomY;
  meteora.vel = randomVel;

	//Righe di codice per il 1° livello di debug.
  D1(cout<<"\tX: "<<meteora.posX<<" Y:"<<meteora.posY<<endl;
    cout<<"\tAngolo: "<<meteora.degrees<<" Velocita': "<<meteora.vel<<endl;
    )
}



/** Ogni meteora "non in vita", in un istante casuale, viene resa "in vita" e gli viene
* assegnato un lato di spawn, posizione verticale, angolazione, velocità ed
* un tipo casuale, a cui corrispondono una bitmap e il relativo indice di scala.
* Viene chiamata la funzione ::genRandomVal per generare i valori casuali necessari, mentre
* ::assegnaTipo e ::assegnaPos_e_moto per gli altri attributi.
*/
void generaMeteora(Meteora meteora[], int nmax, ALLEGRO_BITMAP *icone[]) {


  int randomVel,randomX,randomY,randomAng,randomTipo;
  genRandomVal(randomVel,randomX,randomY,randomAng,randomTipo);


  for(int i=0; i<nmax;i++) {

    if(!meteora[i].inVita) {

    /** Una meteora viene resa "in vita" in un istante casuale.
      */
      if(rand() % 200 == 0) {
        D1(cout<<"Generata meteora "<<i+1<<endl;)
        meteora[i].inVita = true;

        assegnaTipo(meteora[i],randomAng,icone);
        assegnaPos_e_moto(meteora[i],randomX,randomY, randomVel,randomAng);
      break;
      } //FINE "if(rand() % 200 == 0)"
    }
  } //FINE CICLO FOR
}


