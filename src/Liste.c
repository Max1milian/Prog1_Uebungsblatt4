/*
 * Liste.c
 *
 *  Created on: 12.12.2022
 *      Author: student
 */

#include "Liste.h"
Liste* liste_erzeugen()
{
	Liste* L = (struct Liste*) malloc(sizeof(struct Liste));
	L->kopf_ptr = NULL;
	L->laenge = 0;
	return L;
}

void liste_einfuegen_kopf(Liste* liste_ptr, Element* element_ptr)
{
	/*
	Element *e = (struct Element*) malloc(sizeof(struct Element));
	e->value = value;
	e->pSuccessor = list->head; //kopf der übergebenenen List
	list->head = e; //Element wird neuer Kopf
	*/
	liste_ptr->kopf_ptr = element_ptr;
	liste_ptr->laenge++;

}

Element* liste_entferne_ende(Liste* liste_ptr)
{
	//Aufgabe 2c)
	//TODO
	return NULL;
}
