/* mechanik.c
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
#include "mechanik.h"

void mechanik()
{
	char ja[3] = "ja";
	char Ja[3] = "Ja";
	int formel = 0;
	char reg[3] = "no";
	char weitereRechnungHang[3] = "ja";
	
	while(strcmp (weitereRechnungHang, ja) == 0 || strcmp (weitereRechnungHang, Ja) == 0)
	{
		printf("Willst du eine Rechunng aus der Mechanik ausführen? Wenn ja, dann schreibe ja oder Ja.\n");
		scanf("%s", weitereRechnungHang);
		fflush(stdin);
		
		system("cls");
	}
	return;
}