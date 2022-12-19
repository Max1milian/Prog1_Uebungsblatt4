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
#include <ncurses.h>

/*
 * Initialisiert alle Attribute
 */
void schlange_init (Schlange* schlange_ptr)
{
	Liste* L = liste_erzeugen();
	schlange_ptr->positionen_ptr = L;
	schlange_ptr->punkte = 0;
	schlange_ptr->wachsen = 0;
}

Schlange* schlange_erzeugen()
{
	Schlange* snek = (Schlange*)calloc(2, sizeof(struct Schlange));
	if (snek == NULL) {
		printw("Fehler bei der Initialisierung der Schlange\n");
		exit(-1);
	}
	schlange_init(snek);
	return snek;
}


/*
 * Funktion bewegt die Schlange in die angegebene Richtung
 * */
void schlange_bewege (Schlange* schlange_ptr, int richtung)
{
	
		Element* alterKopf = schlange_ptr->positionen_ptr->kopf_ptr;
		
		//die Schlange wird erst als ein Punkt erzeugt und dann zieht sie sich aus wie eine ziehermonika
		if (schlange_ptr->wachsen > 0) {
			//hat noch nicht die ganze länge erreicht
			schlange_ptr->wachsen--;	
		} else if (schlange_ptr->wachsen == 0) {
			//länge wurde erreicht
			Element* entferntesEnde = liste_entferne_ende(schlange_ptr->positionen_ptr);	
			free(entferntesEnde);
		}

		Element* neuerKopf = element_erzeugen();
		neuerKopf->pos.x = alterKopf->pos.x;
		neuerKopf->pos.y = alterKopf->pos.y;

		switch (richtung) {
		case BEWEGUNG_HOCH:
			neuerKopf->pos.y--;
			break;
		case BEWEGUNG_RUNTER:
			neuerKopf->pos.y++;
			break;
		case BEWEGUNG_LINKS:
			neuerKopf->pos.x--;
			break;
		case BEWEGUNG_RECHTS:
			neuerKopf->pos.x++;
			break;
	}
		liste_einfuegen_kopf(schlange_ptr->positionen_ptr,neuerKopf);
}

/*
 * Zeichnet die Schlange auf der Konsole
 */
void schlange_zeichne(Schlange* schlange_ptr, int farbe)
{
	//Aufgabe 3d)
	attron(COLOR_PAIR(farbe)); //Setzt die Farbe der Schrift und des Hintergrunds
	Element* element = schlange_ptr->positionen_ptr->kopf_ptr; //hier übergeben wir den Kopf der Schlange
	while (element != NULL) {//wir laufen durch die schlange durch und zeichnen jedes Element drauf
		console_zeichne_punkt(element->pos.x, element->pos.y, ' '); 
		element = element->nachfolger_ptr;
	}
}
