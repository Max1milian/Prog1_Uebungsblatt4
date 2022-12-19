/*
 * Element.c
 *
 *  Created on: 12.12.2022
 *      Author: student
 */
#include "Element.h"
#include <stdbool.h>
#include <stdio.h>
#include <ncurses.h>
Element* element_erzeugen()
{
	//hier erzeugen wir das Element auf dem Heap
	//
	Element* e = (struct Element*) calloc(2, sizeof(struct Element));
	//error checking! Wenn kein Speicher allociert werden konnte soll das Programm terminieren
	if (e == NULL) {
		printw("Fehler bei erzeugen des Elements!\n");
		exit(-1);
	}
	e->nachfolger_ptr = NULL;
	e->pos.x = 0;
	e->pos.y = 0;
	return e;
}

/* Prüfe, ob e1 mit einem seiner Nachfolger übereinstimmt */
bool element_folge_pruefen (Element* pruef_ptr, Element* e_ptr)
{
	
	while (e_ptr->nachfolger_ptr != NULL)
	{
		//Hier soll über die gesamte Liste des Prüfpointers durchiteriert werden.
		//ist die Position von x oder y gleich dem e_ptr so wird 1 zurück gegeben
		if (pruef_ptr->pos.x == e_ptr->pos.x || pruef_ptr->pos.y == e_ptr->pos.y)
		{
			return true;
		}
		//hier iterieren wir durch die Schlange durch
		e_ptr = e_ptr->nachfolger_ptr;
	}
	return false;
}
