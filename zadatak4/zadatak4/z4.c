#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MaxDegree 10

struct Polynomial {
	int coeffArray[MaxDegree + 1];
	int HighPower;

};

typedef struct Polynomial* Polynom;

void zeroPolynomial(Polynom Poly);
void ReadPolynomial(Polynom, char*);
void printPolynomial(struct Polynomial);
void addPolynomial(Polynom, Polynom, Polynom);
void mulPolynomial(Polynom, Polynom, Polynom);

int Max(int, int);

void main()
{
	struct Polynomial P1, P2, S, P;

	zeroPolynomial(&P1);
	ReadPolynomial(&P1, "polinomi.txt");
	printPolynomial(P1);

	zeroPolynomial(&P2);
	ReadPolynomial(&P2, "polinomi2.txt");
	printPolynomial(P2);


	zeroPolynomial(&S);
	addPolynomial(&P1, &P2, &S);
	printf("\n\nSuma je: ");
	printPolynomial(S);

	zeroPolynomial(&P);
	mulPolynomial(&P1, &P2, &P);
	printf("\n\n Produkt je: ");
	printPolynomial(P);

	printf("\n");
}


void zeroPolynomial(Polynom Poly)
{
	int i;

	for (i = 0; i <= MaxDegree; i++)
		Poly->HighPower = 0;

}

void ReadPolynomial(Polynom P, char* ime_dat)
{
	FILE* dat;
	int coeff, exponent;
	char term[50];

	dat = fopen(ime_dat, "r");
	if (NULL ==dat)
	{
		printf("Greska u otvaranju datoteke!");
		exit(1);
	}
	else {
		while (fscanf(dat, " %s", term) != EOF)
		{
			if (sscanf(term, "%dx^%d", &coeff, &exponent) == 2)
			{
				P->coeffArray[exponent] = coeff;
			}
		}
	}
	int i = MaxDegree;
	while (P->coeffArray[i] == 0 && i != 0)
		i--;

	P->HighPower = i;

}
void printPolynomial (struct Polynomial P )
{
int i;

printf("\n");

for (i = P.HighPower; i >= 0; i--)
if (P.coeffArray[i] > 0)
printf("\t +%d*x^%d", P.coeffArray[i], i);
else if (P.coeffArray[i] < 0)
	printf("\t %d*x^%d", P.coeffArray[i], i);

printf("\n");
}

void addPolynomial(Polynom P1, Polynom P2, Polynom S)
{
	int i;

	S->HighPower = Max(P1->HighPower, P2->HighPower);

	for (i = S->HighPower; i >= 0; i--)
		S->coeffArray[i] = P1->coeffArray[i] + P2->coeffArray[i];

}

int Max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;

}

void mulPolynomial(Polynom P1, Polynom P2, Polynom P)
{
	int i, j;

	P->HighPower = P1->HighPower + P2->HighPower;

	if (P->HighPower > MaxDegree)
		printf("Produkt je nemoguce izracunati jer je rezultantni niz prevelike dimenzije!");
	else
		for (i = P1->HighPower; i >= 0; i--)
			for (j = P2->HighPower; j >= 0; j--)
				P->coeffArray[i + j] = P->coeffArray[i + j] + P1->coeffArray[i] * P2->coeffArray[j];

}







