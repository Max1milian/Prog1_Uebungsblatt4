/*
 * Schlange.c
 *
 *  Created on: 12.12.2022
 *      Author: student
 */
#include <stdlib.h>
#include "Configuration.h"
#include "Schlange.h"
#include "Console.h"

/*
 * Initialisiert alle Attribute
 */
void schlange_init (Schlange* schlange_ptr)
{
	//Aufgabe 3a)
	//TODO
	Liste* L = liste_erzeugen();
	schlange_ptr->positionen_ptr = L;
	schlange_ptr->punkte = 0;
	schlange_ptr->wachsen = 0;
}

Schlange* schlange_erzeugen()
{
	Schlange* snek = (Schlange*)malloc(sizeof(struct Schlange));
	schlange_init(snek);
	return snek;
}


/*
 * Funktion bewegt die Schlange in die angegebene Richtung
 * */
void schlange_bewege (Schlange* schlange_ptr, int richtung)
{
	//Aufgabe 3c)
	//TODO
}

/*
 * Zeichnet die Schlange auf der Konsole
 */
void schlange_zeichne(Schlange* schlange_ptr, int farbe)
{
	//Aufgabe 3d)
	//TODO
	attron(COLOR_PAIR(farbe)); //Setzt die Farbe der Schrift und des Hintergrunds
}

/*
 * Die Funktion verändert die Schlange in Abhängigkeit des eingesammelten Pickups.
 * Alles ist denkbar. Beschleunigung, Wurmloch oder ähnliches.
 */
void schlange_bearbeite_pickup(Schlange* schlange_ptr, char pickup)
{
	//Aufgabe 3e) OPTIONAL
	//TODO
}

/*
 * Die Funktion sollte nach jeder Bewegung aufgerufen werden und zum Beispiel den
 * Punktestand in Abhängigkeit der Länge der Schlange oder der Spieldauer erhöhen.
 */
void schlange_aktualisiere(Schlange* schlange_ptr)
{
	//Aufgabe 3f) OPTIONAL
	//TODO
}
