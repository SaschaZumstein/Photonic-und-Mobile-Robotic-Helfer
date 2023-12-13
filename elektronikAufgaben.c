/* elektronikAufgaben.c
Das Programm soll ein Helfer fuer Photonics und Mobile Robotics Studenten sein.
Autor: _________, __________
Firma: FHGR
Version: 0.1
Datum: 4.12.2023
Änderungen: 
1.0_4.12.2023 Erste Version 
*/

// Einbinden von Headerdateien der Programmbibliothek.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "elektronikAufgaben.h"

// Definitionen
#define ja "ja"
#define Ja "Ja"

// Funktionsprototypen
void eingabe(int *thema, int *schwierigkeit);

void elektronikAufgaben()
{
	char weitereAufgabe[] = "ja";
	int thema = 0;
	int schwierigkeit = 0;

	// Durch die While-Schleife kann das Programm mehrmals ausgefuert werden.
	while(strcmp (weitereAufgabe, ja) == 0 || strcmp (weitereAufgabe, Ja) == 0)
	{
		// Eingabe des Themas und des Schwierigkeitsgrades
		eingabe(&thema, &schwierigkeit);

		// Abfrage ob eine weitere Aufgabe durchgefuert werden soll
		printf("\nWillst du eine weitere Aufgabe durchfueren? Wenn ja, dann schreibe ja oder Ja.\n");
		scanf("%s", weitereAufgabe);
		fflush(stdin);
		system("cls");
	}
	return;
}

// Eingabe des Themas und des Schwierigkeitsgrades
void eingabe(int *thema, int *schwierigkeit) 
{
	// Menü für Eingabe des Themas
	printf("\nFuer Aufgaben zum Ohmschen Gesetz waehle die 1.\n");
	printf("Fuer Aufgaben zu den Kirhoffschen Gesetzen waehle die 2.\n");
	printf("Fuer Aufgaben zu Kondensatoren waehle die 3.\n");
	printf("Fuer Aufgaben zu Spulen waehle die 4.\n");
	printf("Fuer Aufgaben zu Dioden waehle die 5.\n");
	printf("Fuer Aufgaben zu Transistoren waehle die 6.\n");
	
	// Eingabe des Themas
	printf("\nWelches Thema willst du bearbeiten: ");
	scanf("%i" ,thema);
	fflush(stdin);

	// Eingabe des Schwierigkeitsgrad
	printf("\nGib einen Schwierigkeitsgrad zwischen 1 und 3 für deine Aufgabe ein: ");
	scanf("%i" ,schwierigkeit);
	fflush(stdin);
}