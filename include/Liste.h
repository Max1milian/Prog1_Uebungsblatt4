/*
 * Liste.h
 *
 *  Created on: 12.12.2022
 *      Author: student
 */

#ifndef LISTE_H
#define LISTE_H
#include "Element.h"
#include <stdint.h>
struct Liste
{
	//wir setzen zwei pointer, einmal für den Kopf und einmal für das Ende
	//dies macht spätere Aufgaben etwas leichter
	Element* kopf_ptr;
	Element* ende_ptr;
	int32_t laenge;
};
typedef struct Liste Liste;
Liste* liste_erzeugen();

void liste_einfuegen_kopf(Liste* liste_ptr, Element* element_ptr);
Element* liste_entferne_ende(Liste* liste_ptr);

#endif /* LISTE_H_ */
