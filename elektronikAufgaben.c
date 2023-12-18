/* elektronikAufgaben.c
Ein Programm welches verschiedene Aufgaben zur Elektronik zur Verfügung stellt.
Autor: Lennard Zimmermann, Sascha Zumstein
Firma: FHGR
Version: 1.0
Datum: 18.12.2023
Änderungen: 
1.0_18.12.2023 Erste Version 
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
void ohmschesGesetz(int *schwierigkeit, float *loesung, float *musterloesung);
void kondensator(int *schwierigkeit, float *loesung, float *musterloesung);
void spule(int *schwierigkeit, float *loesung, float *musterloesung);
void diode(int *schwierigkeit, float *loesung, float *musterloesung);
float eingabeLoesung();
void loesungsweg(int *thema, int *schwierigkeit);

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
				case 1: 	// Aufgaben zum Ohmschen Gesetz
							ohmschesGesetz(&schwierigkeit, &loesung, &musterloesung);
							break;
				case 2: 	// Aufgaben zum Kondensator
							kondensator(&schwierigkeit, &loesung, &musterloesung);
							break;
				case 3: 	// Aufgaben zur Spule
							spule(&schwierigkeit, &loesung, &musterloesung);
							break;
				case 4: 	// Aufgaben zu Dioden
							diode(&schwierigkeit, &loesung, &musterloesung);
							break;
				default: 	printf("Du hast eine falsche Eingabe für das Thema gemacht.\n");
							break;
			}

			// Lösung korrekt
			if(loesung == musterloesung){
				printf("Bravo, die eingegebene Loesung %f ist korrekt\n", loesung);
				loesungsweg(&thema, &schwierigkeit);
			}
			// Loesung falsch
			else {
				printf("Ihre eingegebene Lösung %f ist leider falsch\n", loesung);
				printf("Um es noch mal zu probieren, druecke die 1, um die Loesung zu sehen, druecke eine andere Taste: ");
				scanf("%i", &tryAgain);
				fflush(stdin);
				// Musterlösung ausgeben
				if(tryAgain != 1) {
					loesungsweg(&thema, &schwierigkeit);
					printf("Die eingegebene Loesung ist: %f\n", loesung);
				}
				else {
					// Konsole löschen
					system("cls");
				}
			}
		} while(tryAgain == 1);

		// Abfrage ob eine weitere Aufgabe durchgefuert werden soll
		printf("\nWillst du eine weitere Elektronik-Aufgabe durchfueren? Wenn ja, dann schreibe ja oder Ja.\n");
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
void ohmschesGesetz(int *schwierigkeit, float *loesung, float *musterloesung){
	if((*schwierigkeit) == 1) {
		printf("Sie haben 2 parallel geschaltene Widerstände mit R1 = R2 = 120ohm.\n");
    	printf("Wie gross ist die Spannung in Volt, wenn ein Gesamtstrom von 120mA fliesst?\n");
		*musterloesung = 7.2;
	}
	else if((*schwierigkeit) == 2) {
		printf("R1 ist parallel mit R2, R3 ist parallel mit R4. Die Parallelschaltungen sind in Serie geschaltet.\n");
    	printf("R1 = 50 Ohm\t R2 = 150 Ohm\t R3 = 1 kOhm\t R4 = 50 Ohm\n");
    	printf("Wie gross ist der Gesamtwiderstand in Ohm auf zwei Komastellen gerundet?\n");
		*musterloesung = 85.120000;
	}
	else if((*schwierigkeit) == 3){
		printf("R1 und R3 sind in Serie geschaltet. Ebenso sind R2 und R4 Seriell\n");
    	printf("R1 und R3 sind parallel zu R2 und R4 geschalten\n");
    	printf("R1 = 150 Ohm\t R2 = 1 kOhm\t R3 = 2.35 kOhm\t R4 = 1.5 kOhm\n");
   		printf("Wie gross ist der Gesamtwiderstand dieser Konfiguration in kOhm?\n");
		*musterloesung = 1.25;
	}
	*loesung = eingabeLoesung();
}

// Aufgaben für Kondensator
void kondensator(int *schwierigkeit, float *loesung, float *musterloesung){
	if((*schwierigkeit) == 1) {
		printf("Kondensator mit Schwierigkeit 1\n");
		*musterloesung = 21;
	}
	else if((*schwierigkeit) == 2) {
		printf("Kondensator mit Schwierigkeit 2\n");
		*musterloesung = 22;
	}
	else if((*schwierigkeit) == 3){
		printf("Kondensator mit Schwierigkeit 3\n");
		*musterloesung = 23;
	}
	*loesung = eingabeLoesung();
}

// Aufgaben für Spulen
void spule(int *schwierigkeit, float *loesung, float *musterloesung){
	if((*schwierigkeit) == 1) {
		printf("Spule mit Schwierigkeit 1\n");
		*musterloesung = 31;
	}
	else if((*schwierigkeit) == 2) {
		printf("Spule mit Schwierigkeit 2\n");
		*musterloesung = 32;
	}
	else if((*schwierigkeit) == 3){
		printf("Spule mit Schwierigkeit 3\n");
		*musterloesung = 33;
	}
	*loesung = eingabeLoesung();
}

// Aufgaben für Dioden
void diode(int *schwierigkeit, float *loesung, float *musterloesung){
	if((*schwierigkeit) == 1) {
		 printf("Wie gross ist die Spannung in Volt, ab der eine Silizium-Halbleiterdiode in Durchlassichtung leitet?\n ");
		*musterloesung = 0.7;
	}
	else if((*schwierigkeit) == 2) {
		printf("Wie entsteht die Sperrschicht in einer Diode?\n");
    	printf("1) Es wird eine Spannung von 0.7V angelegt.\n\n");
   		printf("2) Die Löcher und Elektronen kommen sich sehr nahe und neutralisieren sich.\n\n");
    	printf("3) Löcher werden von der Anode und Elektronen von der Kathode angezogen.\ndadurch entsteht dazwischen ein grosser Freiraum.\n");
		*musterloesung = 3;
	}
	else if((*schwierigkeit) == 3){
		printf("Diode mit Schwierigkeit 3\n");
		*musterloesung = 43;
	}
	// Eingabe der Lösung
	*loesung = eingabeLoesung();
}

// Eingabe der Lösung
float eingabeLoesung(){
	// Variablen definieren
	float loesung = 0;
	int check = 0;
	
	while(check == 0) {
		printf("Bitte gib die Lösung fuer die soeben gestellte Aufgabe ein: ");
		check = scanf("%f" ,&loesung);
		fflush(stdin);
		if(check == 0){
			printf("Die Loesung muss eine Zahl sein und kann kein Zeichen sein\n");
		}
	}
	return loesung;
}

void loesungsweg(int *thema, int *schwierigkeit){
	switch (*thema) {
		case 1: 	if((*schwierigkeit) == 1) {
 						printf("Um den Gesamtwiderstand aus R1 und R2 zu berechnen gilt: 1/R = (1/R1) + (1/R2).\n");
    					printf("Da R1=R2 ist, gilt R= R1/2. Somit gilt: R = 120Ohm/2 = 60Ohm.\n ");
   						printf("Nach dem Ohmschen Gesetz gilt: U= R * I = 60Ohm * 0.12A = 7.2V\n");
					}
					else if((*schwierigkeit) == 2){
						printf("Die korrekte Formel lautet: R = (R1*R2)/(R1+R2) + (R3*R4)/(R3+R4)\n");
    					printf("Der Gesamtwiderstand der Schaltung beträgt somit 85.12 Ohm\n");
					}
					else if((*schwierigkeit) == 3){
						printf("Da R1 und R3, sowie R2 und R4 jeweils Parallel geschalten sind gilt:\n");
    					printf("(R1+R3)*(R2+R4) / (R1+R2+R3+R4)\n");
    					printf("Da R1+R3 = R2+R4 ist, halbiert sich der Gesamtwiderstand und ergibt 1.25kOhm\n");
					}
					break;
		case 2: 	if((*schwierigkeit) == 1) {

					}
					else if((*schwierigkeit) == 2){

					}
					else if((*schwierigkeit) == 3){
						
					}
					break;
		case 3: 	if((*schwierigkeit) == 1) {

					}
					else if((*schwierigkeit) == 2){

					}
					else if((*schwierigkeit) == 3){
						
					}
					break;
		case 4: 	if((*schwierigkeit) == 1) {
						printf("Die Spannung beträgt ca 0.7V\n");
					}
					else if((*schwierigkeit) == 2){
						printf("1) ist Falsch, da die angelegte Spannung die Sperrschicht nicht erzeugt.\n");
    					printf("3) ist falsch, da Elektronen von der Kathode (negativ geladen) angezogen werden und in Richtung Anode (positiv geladen) fliessen,\n");
            			printf("Löcher (positive Ladungsträger, die durch Elektronenmangel entstehen) werden von der Anode angezogen und fließen in Richtung Kathode.\n");
					}
					else if((*schwierigkeit) == 3){
						
					}
					break;
		default: 	printf("Du hast eine falsche Eingabe für das Thema gemacht.\n");
					break;
	}
}