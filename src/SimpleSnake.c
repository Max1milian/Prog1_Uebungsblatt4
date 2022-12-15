/*
 ============================================================================
 Name        : SimpleSnake.c
 Author      : StudentT
 Version     :
 Copyright   : Hochschule Augsburg
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

// Informationen zu ncurses => https://de.wikibooks.org/wiki/Ncurses:_Grundlegendes#ncurses_und_I/O-Befehle_von_C
// Informationen zu ncurses => https://openbook.rheinwerk-verlag.de/linux_unix_programmierung/Kap13-002.htm

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "Schlange.h"
#include "Console.h"
#include "Eingabe.h"
#include "Configuration.h"
#include "Spiel.h"

int main(void) {

	//Startet ncurses und initialisiert es
	console_init();

	//Zeichne den Spielfeldrand
	spiel_zeichne_rand();

	//Erzeugt eine Struktur zum Einlesen
	Eingabe* eingabe_ptr = eingabe_erzeugen();

	//Erzeugt ein Spiel mit zwei Schlangen und initialisiert es
	Spiel* spiel_ptr = spiel_erzeugen();

	while(spiel_ptr->run == 1)
	{
		//Einlesen der Eingabe
		eingabe_einlesen(eingabe_ptr);

		//Zeichne Schlange 1
		schlange_zeichne(spiel_ptr->s1_ptr, SPIELFELD_HINTERGRUND_FARBE);
		schlange_bewege(spiel_ptr->s1_ptr, eingabe_ptr->letzte_eingabe_spieler_1);
		schlange_zeichne(spiel_ptr->s1_ptr, SPIELER_1_FARBE);

		//Zeichne Schlange 2
		schlange_zeichne(spiel_ptr->s2_ptr, SPIELFELD_HINTERGRUND_FARBE);
		schlange_bewege(spiel_ptr->s2_ptr, eingabe_ptr->letzte_eingabe_spieler_2);
		schlange_zeichne(spiel_ptr->s2_ptr, SPIELER_2_FARBE);

		//Prüfe auf Kollission => Relevant für Spielende
		spiel_pruefe_kollission(spiel_ptr);

		//Spielzeit erhöhen
		spiel_ptr->schritte++;

		//Pausieren des Main-Thread - Spielgeschwindigkeit
		usleep(SPIEL_GESCHWINDIGKEIT);
	}

	//Warte auf Tastendruck
	getchar();

	return EXIT_SUCCESS;
}
