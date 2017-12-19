#include <iostream>
using namespace std;

/** Inizio interfaccia */

// Sezione per il debug

/** Valore di MASK
* 1: debug-livello1
* 2: debug-livello2
*	3: debug-livello1 + debug-livello2
*/
#define MASK 1

/** Se l'espressione risulta true, viene scritta la riga di codice
* del tipo D<A>(<istruzioni>); altrimenti viene cancellata.
*/
#define DBG(A,B) {if ((A) & MASK) {B; } }

/** Debug-livello1: stampa su cout degli attributi delle meteore generate. */
#define D1(a) DBG(1,a)

/** Debug-livello2: stampa su cout di ogni cambiamento di stato */
#define D2(a) DBG(2,a)

// Fine sezione per il debug


#define WIDTH 800
#define HEIGHT 640


//Strutture dati

/**Enumerazione che semplifica la verifica del
* tipo delle istanze di Meteora.
*/
enum Tipo{PICCOLA,MEDIA,GRANDE};


/** Rappresenta la "navicella" controllata dal giocatore.
* E' dotata di rappresentazione grafica (sprite), nonchè di valori
* che rappresentano i punti vita rimasti (vita) e i punti acquisiti distruggendo
* le meteore (punteggio).
* posX e posY indicano le coordinate del centro di sprite, tenendo conto che nel display
* il punto (0,0) corrisponde all'angolo superiore sinistro, e le direzioni di crescita di x e y
* sono rispettivamente verso destra e verso il basso.
* angolo rappresenta l'angolo di Player, che ne determinerà la direzione di spostamento.
* vel è la velocità che avrà Player in movimento.
*/
struct Player {

  ALLEGRO_BITMAP *sprite;

  int vita;
  int punteggio;

  int posX;
  int posY;
  double angolo;

  int vel;
};


struct Colpo {

  bool attivo;

  int posX;
  int posY;

  double degrees;
  int vel;
};

/** Rappresenta la "meteora" che il giocatore dovrà schivare e/o distruggere.
* E' dotata di rappresentazione grafica (sprite), nonchè di valori
* che rappresentano il suo stato attuale (inVita) ed il tipo, a cui corrisponde una diversa sprite,
* e che ne determina un opportuno raggio,bordo (per le collisioni) e un indice di scala per la sprite
* stessa.
* posX e posY indicano le coordinate del centro di sprite, tenendo conto che nel display
* il punto (0,0) corrisponde all'angolo superiore sinistro, e le direzioni di crescita di x e y
* sono rispettivamente verso destra e verso il basso.
* degrees rappresenta l'angolo di Meteora, che ne determinerà la direzione di spostamento.
* vel è la velocità che avrà Player in movimento.
*/
struct Meteora {

  ALLEGRO_BITMAP *sprite;

  Tipo tipo;
  bool inVita;

  int raggio;
  int bordo;
  double scala;

  int posX;
  int posY;

  int vel;
  double degrees;
  double dirX;
};
//Fine strutture dati

/** Fine interfaccia */
