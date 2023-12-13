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
void ohmschesGesetz(int schwierigkeit);
void kirhoff(int schwierigkeit);
void kondensator(int schwierigkeit);
void spule(int schwierigkeit);
void diode(int schwierigkeit);
void transistor(int schwierigkeit);

void elektronikAufgaben()
{
	// Variable deklarieren
	char weitereAufgabe[] = "ja";
	int thema = 0;
	int schwierigkeit = 0;

	// Durch die While-Schleife kann das Programm mehrmals ausgefuert werden.
	while(strcmp (weitereAufgabe, ja) == 0 || strcmp (weitereAufgabe, Ja) == 0)
	{
		// Eingabe des Themas und des Schwierigkeitsgrades
		eingabe(&thema, &schwierigkeit);

		// Auswahl des Thema
		switch(thema) {
			case 1: 	ohmschesGesetz(schwierigkeit);
						break;
			case 2: 	kirhoff(schwierigkeit);
						break;
			case 3: 	kondensator(schwierigkeit);
						break;
			case 4: 	spule(schwierigkeit);
						break;
			case 5: 	diode(schwierigkeit);
						break;
			case 6: 	transistor(schwierigkeit);
						break;
			default: 	printf("Du hast eine falsche Eingabe für das Thema gemacht.\n");
						break;
		}

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
	thema = 0;
	while((*thema)<1 || (*thema)>6){
		printf("\nWelches Thema willst du bearbeiten: ");
		scanf("%i" ,thema);
		fflush(stdin);
		if((*thema)<1 || (*thema)>6){
			printf("Du kannst nur die Themen aus der Liste auswählen, versuche es noch einmal\n");
		}
	}

	// Eingabe des Schwierigkeitsgrad
	schwierigkeit = 0;
	while((*schwierigkeit)<1 || (*schwierigkeit)>3){
		printf("\nGib den Schwierigkeitsgrad zwischen 1 und 3 deiner Aufgabe ein: ");
		scanf("%i" ,schwierigkeit);
		fflush(stdin);
		if((*schwierigkeit)<1 || (*schwierigkeit)>3){
			printf("Du kannst nur die Schwierigkeitsgrade 1, 2 oder 3 eingeben, versuche es noch einmal\n");
		}
	}
}