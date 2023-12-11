/* vector.c
Beschreibung: Kreuz- und Skalarprodukt sowie Betrag eines Vektors.
Autor: Ramon Tarca, Ryoya Bauer
Firma: FHGR 
Version: 1.0 
Datum: 04.12.2023 
Änderungen: 
1.0 04.12.2023 Erste Version 
2.0 6.12.2023 Einfuegen der while-Schleife
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


void norm(void);
void cross(void);
void dot(void);
void distance2D(void);
void distance3D(void);
float normInternal(int n, float *vector);
float crossInternal(int n, float *vector1, float *vector2);
float dotInternal(int n, float *vector1, float *vector2);

void vector()
{
	char ja[3] = "ja";
	char Ja[3] = "Ja";
	char weitereRechnungVec[3] = "ja";
	
	while(strcmp (weitereRechnungVec, ja) == 0 || strcmp (weitereRechnungVec, Ja) == 0)
	{
		int menue = 0;
			
		printf("\n1 - Betrag eines Vektors in n\n");
		printf("2 - Kreuzprodukt in 3D\n");
		printf("3 - Skalarprodukt in n\n");
		printf("4 - Abstand Punkt-Gerade in 2D\n");
		printf("5 - Abstand Punkt-Gerade in 3D\n");
		scanf("%i", &menue);
		fflush(stdin);
		
		switch(menue)
		{
			case 1: 
				norm(); 
				break;
			case 2: 
				cross(); 
				break;
			case 3: 
				dot();
				break;
			case 4: 
				distance2D(); 
				break;
			case 5: 
				distance3D(); 
				break;
			default:
				printf("Der eingegebene Wert ist keinem Programm zugewiesen!\n\n");
				return;
		}
		
		printf("Willst du eine weitere Operation mit Vektoren durchfueren? Wenn ja, dann schreibe ja oder Ja.\n");
		scanf("%s" ,&weitereRechnungVec);
		fflush(stdin);
		
		system("cls");
	}
}

void norm(void)
{
	int n = 0;
	printf("\nBitte Dimension wählen:\n");
	scanf("%i",&n);
	fflush(stdin);
	float vector1[n];
	
	printf("\nBitte den Vektor abfüllen:\n");
	
	for(int i = 0; i < n; i++)
	{
		scanf("%f",&vector1[i]);
		fflush(stdin);		// Buffer leeren um scanf() nochmals auszuführen
	}
		
	float result = 0;
	
	for(int i = 0; i < n; i++)
	{
		result += vector1[i] * vector1[i];
	}
	
	result = sqrtf(result);
	
	printf("\nDer Betrag ist %f\n\n",result);
	return;
}

void cross(void)
{
	int n = 3;
	float vector1[n], vector2[n];
	
	printf("\nBitte den ersten Vektor abfüllen:\n");
	
	for(int i = 0; i < n; i++)
	{
		scanf("%f",&vector1[i]);
		fflush(stdin);		// Buffer leeren um scanf() nochmals auszuführen
	}
		
	printf("\nBitte den zweiten Vektor abfüllen:\n");
	
	for(int i = 0; i < n; i++)
	{
		scanf("%f",&vector2[i]);
		fflush(stdin);		// Buffer leeren um scanf() nochmals auszuführen
	}
	
	float result[n];
	
	int count1 = 1;
	int count2 = 2;
	
	for(int i = 0; i < n; i++)
	{
		result[i] = vector1[count1] * vector2[count2] - vector1[count2] * vector2[count1];
		count1++;
		count2++;
		if (count1 > 2)
		{
			count1 = 0;
		}
		if (count2 > 2)
		{
			count2 = 0;
		}
	}
	
	printf("\nDer neue Vektor lautet:\n");
	for(int i = 0; i < n; i++)
	{
		printf("%f\n",result[i]);
	}
	printf("\n");
	return;
}

void dot(void)
{
	int n = 0;
	printf("\nBitte Dimension wählen:\n");
	scanf("%i",&n);
	fflush(stdin);
	float vector1[n], vector2[n];
	
	printf("\nBitte den ersten Vektor abfüllen:\n");
	
	for(int i = 0; i < n; i++)
	{
		scanf("%f",&vector1[i]);
		fflush(stdin);		// Buffer leeren um scanf() nochmals auszuführen
	}
		
	printf("\nBitte den zweiten Vektor abfüllen:\n");
	
	for(int i = 0; i < n; i++)
	{
		scanf("%f",&vector2[i]);
		fflush(stdin);		// Buffer leeren um scanf() nochmals auszuführen
	}
	
	float result = 0;
	
	for(int i = 0; i < n; i++)
	{
		result += vector1[i] * vector2[i];
	}
	
	printf("\nDas Skalarprodukt ergibt %f\n\n",result);
	return;
}

void tausche(float vector1[]) 
{
    float temp = vector1[0];
    vector1[0] = -vector1[1];
    vector1[1] = temp;
}

void distance2D(void) 
{
    int n = 2;
    float vector1[n], vector2[n], point[n];
    float dotrestult=0;

    printf("d=<P-S0, hut n>\nBitte die Gerade definieren (g):\n"); //Gerade
	
    for (int i = 0; i < n; i++) 
	{
        scanf("%f", &vector1[i]);
        fflush(stdin);
    }

    printf("\n\nBitte einen Punkt auf dieser Gerade definieren (S0):\n"); //s0
    for (int i = 0; i < n; i++) {
        scanf("%f", &vector2[i]);
        fflush(stdin);
    }

    printf("\n\nBitte einen Punkt definieren fuer den Gerade-Punkteabstand (P):\n"); //Abstandspunkt
    for (int i = 0; i < n; i++) {
        scanf("%f", &point[i]);
        fflush(stdin);
    }

    tausche(vector1);

    float normNormal = normInternal(n, vector1);

    printf("\nNormalenvektor:\n");
	for(int i = 0; i < n; i++)
	{
		printf("%f\n",vector1[i]);
	}

	printf("\nBetrag des Normalenvektors: \n%f\n", normNormal);

	float direction[n];
    for (int i = 0; i < n; i++) {
        direction[i] = (1 / normNormal) * vector1[i];
    }

    printf("\nEinheitsnormalenvektor:\n");
	for(int i = 0; i < n; i++)
	{
		printf("%f\n",direction[i]);
	}


    float difference[n];
    for (int i = 0; i < n; i++) {
        difference[i] = point[i] - vector2[i];
    }

    printf("\nP - S0= \n");
	for(int i = 0; i < n; i++)
	{
		printf("%f\n",difference[i]);
	}

    float dotresult = dotInternal(n, difference, direction);
    printf("\nDer Abstand betraegt %f\n", dotresult);

    return;
}

void distance3D(void)
{
	printf("placeholder\n");
}

float normInternal(int n, float *vector1)
{
	float result = 0;

	for(int i = 0; i < n; i++)
	{
		result += vector1[i] * vector1[i];
	}

	result = sqrtf(result);
	return result;
}

float crossInternal(int n, float *vector1, float *vector2) {
    float result[n];
    int count1 = 1;
    int count2 = 2;

    for(int i = 0; i < n; i++) {
        result[i] = vector1[count1] * vector2[count2] - vector1[count2] * vector2[count1];
        count1++;
        count2++;
        if (count1 > 2) {
            count1 = 0;
        }
        if (count2 > 2) {
            count2 = 0;
        }
    }
    return result[n];
}

float dotInternal(int n, float *vector1, float *vector2)
{
	float result = 0;

	for(int i = 0; i < n; i++)
	{
		result += vector1[i] * vector2[i];
	}

	return result;
}