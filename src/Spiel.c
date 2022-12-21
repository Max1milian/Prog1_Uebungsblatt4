/*
 * Spiel.c
 *
 *  Created on: 12.12.2022
 *      Author: student
 */
#include "Configuration.h"
#include "Console.h"
#include "Spiel.h"
#include <stdlib.h>
#include <ncurses.h>

void spiel_init(Spiel* spiel_ptr)
{
	spiel_ptr->s1_ptr = schlange_erzeugen();
	spiel_ptr->s2_ptr = schlange_erzeugen();

	Element* kopfS1 = element_erzeugen();
	Element* kopfS2 = element_erzeugen();
	
	kopfS1->pos.x = SPIELER_1_XPOS;
	kopfS1->pos.y = SPIELER_YPOS;
	liste_einfuegen_kopf(spiel_ptr->s1_ptr->positionen_ptr, kopfS1);
	spiel_ptr->s1_ptr->wachsen = SPIEL_SCHLANGEN_LAENGE;

	kopfS2->pos.x = SPIELER_2_XPOS;
	kopfS2->pos.y = SPIELER_YPOS;
	liste_einfuegen_kopf(spiel_ptr->s2_ptr->positionen_ptr, kopfS2);
	spiel_ptr->s2_ptr->wachsen = SPIEL_SCHLANGEN_LAENGE;
	spiel_ptr->run = 1;

}

Spiel* spiel_erzeugen()
{
	Spiel* neuesSpiel = (Spiel*) calloc(2,sizeof(Spiel));
	if (neuesSpiel == NULL) {
		printw("Fehler beim erzeugen eines Spiels!\n");
		exit(-1);
	}
	spiel_init(neuesSpiel);
	return neuesSpiel;
}

void spiel_zeichne_rand()
{
	attron(COLOR_PAIR(SPIELFELD_RAND_FARBE));

	// Oben zeichnen
	for (int x = SPIELFELD_OFFSET_X; x <= SPIELFELD_XSIZE + SPIELFELD_OFFSET_X + 1; x++) {
		console_zeichne_punkt(x, SPIELFELD_OFFSET_Y, ' ');
	}
	// Rechts zeichnen
	for (int y = SPIELFELD_OFFSET_Y+1; y <= SPIELFELD_YSIZE + SPIELFELD_OFFSET_Y; y++) {
		console_zeichne_punkt(SPIELFELD_OFFSET_X + SPIELFELD_XSIZE + 1, y, ' ');
	}
	// Unten zeichnen
	for (int x = SPIELFELD_OFFSET_X; x <= SPIELFELD_XSIZE + SPIELFELD_OFFSET_X + 1; x++) {
		console_zeichne_punkt(x, SPIELFELD_OFFSET_Y+SPIELFELD_YSIZE+1, ' ');
	}
	// Links zeichnen
	for (int y = SPIELFELD_OFFSET_Y+1; y <= SPIELFELD_YSIZE + SPIELFELD_OFFSET_Y; y++) {
		console_zeichne_punkt(SPIELFELD_OFFSET_X, y, ' ');
	}
}

void spiel_pruefe_kollission(Spiel* spiel_ptr)
{
	char ergebnis = 0;

	// 1) Schlange 1 Schlange 2 beißt
	ergebnis += element_folge_pruefen(spiel_ptr->s1_ptr->positionen_ptr->kopf_ptr, spiel_ptr->s2_ptr->positionen_ptr->kopf_ptr);

	//2) Schlange 1 sich selbst beißt
	ergebnis += element_folge_pruefen(spiel_ptr->s1_ptr->positionen_ptr->kopf_ptr, spiel_ptr->s1_ptr->positionen_ptr->kopf_ptr->nachfolger_ptr);

	// 3) Schlange 1 in den Rand beißt
	int s1x = spiel_ptr->s1_ptr->positionen_ptr->kopf_ptr->pos.x;
	int s1y = spiel_ptr->s1_ptr->positionen_ptr->kopf_ptr->pos.y;
	// 3a) Linker oder Rechter Rand
	if (s1x <= SPIELFELD_OFFSET_X + 1 || s1x >= (SPIELFELD_OFFSET_X + SPIELFELD_XSIZE)) {
		ergebnis += 1;
	}
	// 3b) Linker oder Rechter Rand
	if (s1y <= SPIELFELD_OFFSET_Y + 1 || s1y >= (SPIELFELD_OFFSET_Y + SPIELFELD_YSIZE)) {
		ergebnis += 1;
	}

	// 4) Schlange 2 Schlange 1 beißt
	ergebnis += element_folge_pruefen(spiel_ptr->s2_ptr->positionen_ptr->kopf_ptr, spiel_ptr->s1_ptr->positionen_ptr->kopf_ptr);

	// 5) Schlange 2 sich selbst beißt
	ergebnis += element_folge_pruefen(spiel_ptr->s2_ptr->positionen_ptr->kopf_ptr, spiel_ptr->s2_ptr->positionen_ptr->kopf_ptr->nachfolger_ptr);

	// 6) Schlange 2 in den Rand beißt
	int s2x = spiel_ptr->s2_ptr->positionen_ptr->kopf_ptr->pos.x;
	int s2y = spiel_ptr->s2_ptr->positionen_ptr->kopf_ptr->pos.y;
	// 6a) Linker oder Rechter Rand
	if (s2x <= SPIELFELD_OFFSET_X + 1 || s2x >= (SPIELFELD_OFFSET_X + SPIELFELD_XSIZE)) {
		ergebnis += 1;
	}
	// 6b) Linker oder Rechter Rand
	if (s2y <= SPIELFELD_OFFSET_Y + 1 || s2y >= (SPIELFELD_OFFSET_Y + SPIELFELD_YSIZE)) {
		ergebnis += 1;
	}
	if (ergebnis >= 1) {
		spiel_ptr->run = 0;
	}
}

