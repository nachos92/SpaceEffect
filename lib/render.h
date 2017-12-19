#include <iostream>
using namespace std;

/** Inizio interfaccia */
void disegnaPlayer(Player ship);
void disegnaMeteore(Meteora meteora[],int nmax, ALLEGRO_BITMAP *iconaMeteora);
void disegnaColpo(Colpo colpi[], int nmax);
void playerStat(Player ship, ALLEGRO_BITMAP *cuore, ALLEGRO_FONT *textFont);

void schermataMenu(ALLEGRO_BITMAP *sfondoMenu,ALLEGRO_FONT *menuFont,ALLEGRO_FONT *font);
void schermataPausa(ALLEGRO_FONT *gameoverFont, ALLEGRO_FONT *font);
void schermataGameover(ALLEGRO_BITMAP *sfondoGameover,ALLEGRO_FONT *gameoverFont, ALLEGRO_FONT *punteggioFont, ALLEGRO_FONT *font, const int punteggio);

/** Fine interfaccia */
