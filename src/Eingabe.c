/*
 * Eingabe.c
 *
 *  Created on: 12.12.2022
 *      Author: student
 */

#include "Configuration.h"
#include "Eingabe.h"
#include <ncurses.h>

Eingabe* eingabe_erzeugen ()
{
	Eingabe* e_ptr = (Eingabe*)calloc(2, sizeof(Eingabe));
	eingabe_init(e_ptr);
	return e_ptr;
}

void eingabe_init(struct Eingabe* eingabe_ptr)
{
	eingabe_ptr->letzte_eingabe_spieler_1 = BEWEGUNG_RECHTS;
	eingabe_ptr->letzte_eingabe_spieler_2 = BEWEGUNG_LINKS;
}

void eingabe_einlesen(struct Eingabe* eingabe_ptr)
{
	char c = 'X';
	for (int i = 0; i < 100; i++)
	{
		c = getch();
		switch (c)
		{
			case SPIELER_1_HOCH:
				eingabe_ptr->letzte_eingabe_spieler_1 = BEWEGUNG_HOCH;
				break;
			case SPIELER_2_HOCH:
				eingabe_ptr->letzte_eingabe_spieler_2 = BEWEGUNG_HOCH;
				break;
			case SPIELER_1_RUNTER:
				eingabe_ptr->letzte_eingabe_spieler_1 = BEWEGUNG_RUNTER;
				break;
			case SPIELER_2_RUNTER:
				eingabe_ptr->letzte_eingabe_spieler_2 = BEWEGUNG_RUNTER;
				break;
			case SPIELER_1_LINKS:
				eingabe_ptr->letzte_eingabe_spieler_1 = BEWEGUNG_LINKS;
				break;
			case SPIELER_2_LINKS:
				eingabe_ptr->letzte_eingabe_spieler_2 = BEWEGUNG_LINKS;
				break;
			case SPIELER_1_RECHTS:
				eingabe_ptr->letzte_eingabe_spieler_1 = BEWEGUNG_RECHTS;
				break;
			case SPIELER_2_RECHTS:
				eingabe_ptr->letzte_eingabe_spieler_2 = BEWEGUNG_RECHTS;
				break;
			default:
				break;
				//UNGÜLTIG / UNBEKANNT
		}

		flushinp(); 	// Leert den Puffer
		usleep(100); 	// Hält den Thread für 100 us an.
	}
}

