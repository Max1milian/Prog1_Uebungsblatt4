/*
 * Spiel.h
 *
 *  Created on: 12.12.2022
 *      Author: student
 */

#ifndef SPIEL_H_
#define SPIEL_H_
#include "Schlange.h"
struct Spiel
{
	Schlange* s1_ptr;
	Schlange* s2_ptr;
	char run;
	int schritte;
};
typedef struct Spiel Spiel;

Spiel* spiel_erzeugen();
void spiel_init(Spiel* spiel_ptr);
void spiel_zeichne_rand();
void spiel_zeichne_spielstand();
void spiel_pruefe_kollission(Spiel* spiel_ptr);


#endif /* SPIEL_H_ */
