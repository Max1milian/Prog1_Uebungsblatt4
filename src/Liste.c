/*
 * Liste.c
 *
 *  Created on: 12.12.2022
 *      Author: student
 */

#include "Liste.h"
Liste* liste_erzeugen()
{
	Liste* L = (struct Liste*) calloc(2, sizeof(struct Liste));
	L->kopf_ptr = NULL;
	L->laenge = 0;
	return L;
}

void liste_einfuegen_kopf(Liste* liste_ptr, Element* element_ptr)
{

	if (liste_ptr->laenge == 0) {
		// Erstes Element in der Liste -> Ende der Liste setzen
		liste_ptr->ende_ptr = element_ptr;
	} else {
		// Es gibt schon Elemente -> Vorgänger vom alten Kopf setzen
		liste_ptr->kopf_ptr->vorgaenger_ptr = element_ptr;
	}

	element_ptr->nachfolger_ptr = liste_ptr->kopf_ptr;
	element_ptr->vorgaenger_ptr = NULL;

	liste_ptr->kopf_ptr = element_ptr;
	liste_ptr->laenge++;
}

Element* liste_entferne_ende(Liste* liste_ptr)
{
	//hier erstellen wir ein pointer auf as Element
	Element* element_ptr = liste_ptr->kopf_ptr; //hier übergeben wir den listenkopf pointer damit die Variable initialisiert ist
	if (liste_ptr->kopf_ptr->nachfolger_ptr == NULL) {//gibt uns das letzte Element der liste zurück
		element_ptr = liste_ptr->kopf_ptr->nachfolger_ptr;
		element_ptr->nachfolger_ptr = NULL;
	}
	
		return element_ptr;
}
