#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct osoba Osoba;

struct osoba {
	char ime[20];
	char prezie[20];
	int god_rod;
	Osoba* next;

};