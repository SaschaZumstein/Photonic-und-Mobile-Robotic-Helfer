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
int ohmschesGesetz(int schwierigkeit);
int kondensator(int schwierigkeit);
int spule(int schwierigkeit);
int diode(int schwierigkeit);
int eingabeLoesung();

// Hier steht das Hauptprogramm dieser Funktion
void elektronikAufgaben()
{
	// Variable deklarieren
	char weitereAufgabe[] = "ja";
	int thema = 0;
	int schwierigkeit = 0;
	int loesung = 0;

	// Durch die While-Schleife kann das Programm mehrmals ausgefuert werden.
	while(strcmp (weitereAufgabe, ja) == 0 || strcmp (weitereAufgabe, Ja) == 0)
	{
		// Eingabe des Themas und des Schwierigkeitsgrades
		eingabe(&thema, &schwierigkeit);

		// Auswahl des Thema
		switch(thema) {
			case 1: 	loesung = ohmschesGesetz(schwierigkeit);
						break;
			case 2: 	loesung = kondensator(schwierigkeit);
						break;
			case 3: 	loesung = spule(schwierigkeit);
						break;
			case 4: 	loesung = diode(schwierigkeit);
						break;
			default: 	printf("Du hast eine falsche Eingabe für das Thema gemacht.\n");
						break;
		}

		// Ausgabe der eingegebenen Lösung
		printf("Die eingegebene Loesung ist: %i", loesung);

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
	printf("Fuer Aufgaben zu Kondensatoren waehle die 2.\n");
	printf("Fuer Aufgaben zu Spulen waehle die 3.\n");
	printf("Fuer Aufgaben zu Dioden waehle die 4.\n");
	
	// Eingabe des Themas
	(*thema) = 0;
	while((*thema)<1 || (*thema)>4){
		printf("\nWelches Thema willst du bearbeiten: ");
		scanf("%i" ,thema);
		fflush(stdin);
		if((*thema)<1 || (*thema)>4){
			printf("Du kannst nur die Themen aus der Liste auswählen, versuche es noch einmal\n");
		}
	}

	// Eingabe des Schwierigkeitsgrad
	(*schwierigkeit) = 0;
	while((*schwierigkeit)<1 || (*schwierigkeit)>3){
		printf("\nGib den Schwierigkeitsgrad zwischen 1 und 3 deiner Aufgabe ein: ");
		scanf("%i" ,schwierigkeit);
		fflush(stdin);
		if((*schwierigkeit)<1 || (*schwierigkeit)>3){
			printf("Du kannst nur die Schwierigkeitsgrade 1, 2 oder 3 eingeben, versuche es noch einmal\n");
		}
	}
}

// Aufgaben für Ohmsches Gesetz
int ohmschesGesetz(int schwierigkeit){
	if(schwierigkeit == 1) {
		printf("Ohmsches Gesetz mit Schwierigkeit 1\n");
	}
	else if(schwierigkeit == 2) {
		printf("Ohmsches Gesetz mit Schwierigkeit 2\n");
	}
	else if(schwierigkeit == 3){
		printf("Ohmsches Gesetz mit Schwierigkeit 3\n");
	}
	return (eingabeLoesung());
}

// Aufgaben für Kondensator
int kondensator(int schwierigkeit){
	if(schwierigkeit == 1) {
		printf("Kondensator mit Schwierigkeit 1\n");
	}
	else if(schwierigkeit == 2) {
		printf("Kondensator mit Schwierigkeit 2\n");
	}
	else if(schwierigkeit == 3){
		printf("Kondensator mit Schwierigkeit 3\n");
	}
	return (eingabeLoesung());
}

// Aufgaben für Spulen
int spule(int schwierigkeit){
	if(schwierigkeit == 1) {
		printf("Spule mit Schwierigkeit 1\n");
	}
	else if(schwierigkeit == 2) {
		printf("Spule mit Schwierigkeit 2\n");
	}
	else if(schwierigkeit == 3){
		printf("Spule mit Schwierigkeit 3\n");
	}
	return (eingabeLoesung());
}

// Aufgaben für Dioden
int diode(int schwierigkeit){
	if(schwierigkeit == 1) {
		printf("Diode mit Schwierigkeit 1\n");
	}
	else if(schwierigkeit == 2) {
		printf("Diode mit Schwierigkeit 2\n");
	}
	else if(schwierigkeit == 3){
		printf("Diode mit Schwierigkeit 3\n");
	}
	return (eingabeLoesung());
}

// Eingabe der Lösung
int eingabeLoesung(){
	int loesung = 0;
	printf("Bitte gib die Lösung fuer die soeben gestellte Aufgabe ein: ");
	scanf("%i" ,&loesung);
	fflush(stdin);
	return loesung;
}