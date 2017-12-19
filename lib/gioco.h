#include <iostream>
using namespace std;



/** Inizio implementazione */
bool fuoriSchermo(const int x, const int y);

/** Fine implementazione */


/** Inizio interfaccia */
void ruotaAntiorario(Player &ship, const int gradi);
void ruotaOrario(Player &ship, const int gradi);
void muovi(Player &ship);
void sparaColpo(Colpo colpi[], int nmax, Player ship, ALLEGRO_SAMPLE *shot);
void aggiornaMeteore(Meteora meteora[],int nmax);
void aggiornaColpo(Colpo colpi[],int nmax);
void collisioneColpo(Colpo colpi[], const int maxcolpi, Meteora meteora[], const int maxmeteore, Player &ship, ALLEGRO_SAMPLE *explosion);
void collisioneMeteora(Meteora meteora[], int nmax, Player &ship, ALLEGRO_SAMPLE  *crash);

/** Fine interfaccia */

