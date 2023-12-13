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
float ohmschesGesetz(int *schwierigkeit, float *loesung);
float kondensator(int *schwierigkeit, float *loesung);
float spule(int *schwierigkeit, float *loesung);
float diode(int *schwierigkeit, float *loesung);
float eingabeLoesung();

// Hier steht das Hauptprogramm dieser Funktion
void elektronikAufgaben()
{
	// Variable deklarieren
	char weitereAufgabe[] = "ja";
	int tryAgain = 0;
	int thema = 0;
	int schwierigkeit = 0;
	float loesung = 0;
	float musterloesung = 0;

	// Konsole löschen
	system("cls");

	// Durch die While-Schleife kann das Programm mehrmals ausgefuert werden.
	while(strcmp (weitereAufgabe, ja) == 0 || strcmp (weitereAufgabe, Ja) == 0)
	{
		// Eingabe des Themas und des Schwierigkeitsgrades
		eingabe(&thema, &schwierigkeit);

		do {
			tryAgain = 0;
			// Auswahl des Thema
			switch(thema) {
				case 1: 	musterloesung = ohmschesGesetz(&schwierigkeit, &loesung);
							break;
				case 2: 	musterloesung = kondensator(&schwierigkeit, &loesung);
							break;
				case 3: 	musterloesung = spule(&schwierigkeit, &loesung);
							break;
				case 4: 	musterloesung = diode(&schwierigkeit, &loesung);
							break;
				default: 	printf("Du hast eine falsche Eingabe für das Thema gemacht.\n");
							break;
			}

			// Lösung korrekt
			if(loesung == musterloesung){
				printf("Bravo, die eingegebene Loesung %f ist korrekt\n", loesung);
			}
			// Loesung falsch
			else {
				printf("Ihre eingegebene Lösung %f ist leider falsch\n", loesung);
				printf("Um es noch mal zu probieren, druecke die 1, um die Loesung zu sehen, druecke eine andere Taste: ");
				scanf("%i", &tryAgain);
				fflush(stdin);
				// Musterlösung ausgeben
				if(tryAgain != 1) {
					printf("Die korrekte Loesung ist: %f\n", musterloesung);
					printf("Die eingegebene Loesung ist: %f\n", loesung);
				}
				else {
					// Konsole löschen
					system("cls");
				}
			}
			// Konsole löschen
		} while(tryAgain == 1);

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
float ohmschesGesetz(int *schwierigkeit, float *loesung){
	// Variablen definieren
	float musterloesung;

	if((*schwierigkeit) == 1) {
		printf("Ohmsches Gesetz mit Schwierigkeit 1\n");
		musterloesung = 11;
	}
	else if((*schwierigkeit) == 2) {
		printf("Ohmsches Gesetz mit Schwierigkeit 2\n");
		musterloesung = 12;
	}
	else if((*schwierigkeit) == 3){
		printf("Ohmsches Gesetz mit Schwierigkeit 3\n");
		musterloesung = 13;
	}
	*loesung = eingabeLoesung();
	return musterloesung;
}

// Aufgaben für Kondensator
float kondensator(int *schwierigkeit, float *loesung){
	// Variablen definieren
	float musterloesung;

	if((*schwierigkeit) == 1) {
		printf("Kondensator mit Schwierigkeit 1\n");
		musterloesung = 21;
	}
	else if((*schwierigkeit) == 2) {
		printf("Kondensator mit Schwierigkeit 2\n");
		musterloesung = 22;
	}
	else if((*schwierigkeit) == 3){
		printf("Kondensator mit Schwierigkeit 3\n");
		musterloesung = 23;
	}
	*loesung = eingabeLoesung();
	return musterloesung;
}

// Aufgaben für Spulen
float spule(int *schwierigkeit, float *loesung){
	// Variablen definieren
	float musterloesung;

	if((*schwierigkeit) == 1) {
		printf("Spule mit Schwierigkeit 1\n");
		musterloesung = 31;
	}
	else if((*schwierigkeit) == 2) {
		printf("Spule mit Schwierigkeit 2\n");
		musterloesung = 32;
	}
	else if((*schwierigkeit) == 3){
		printf("Spule mit Schwierigkeit 3\n");
		musterloesung = 33;
	}
	*loesung = eingabeLoesung();
	return musterloesung;
}

// Aufgaben für Dioden
float diode(int *schwierigkeit, float *loesung){
	// Variablen definieren
	float musterloesung;

	if((*schwierigkeit) == 1) {
		printf("Diode mit Schwierigkeit 1\n");
		musterloesung = 41;
	}
	else if((*schwierigkeit) == 2) {
		printf("Diode mit Schwierigkeit 2\n");
		musterloesung = 42;
	}
	else if((*schwierigkeit) == 3){
		printf("Diode mit Schwierigkeit 3\n");
		musterloesung = 43;
	}
	// Eingabe der Lösung
	*loesung = eingabeLoesung();
	return musterloesung;
}

// Eingabe der Lösung
float eingabeLoesung(){
	// Variablen definieren
	float loesung = 0;
	int check = 0;
	
	while(check == 0) {
		printf("Bitte gib die Lösung fuer die soeben gestellte Aufgabe ein: ");
		check = scanf("%i" ,&loesung);
		fflush(stdin);
		if(check == 0){
			printf("Die Loesung muss eine Zahl sein und kann kein Zeichen sein\n");
		}
	}
	return loesung;
}