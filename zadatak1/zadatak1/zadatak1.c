#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define max_bod 50
typedef struct {
	char ime[20], prezime[20];
	int brBod;


}_student;
int main() {

	FILE* fs;
	fs = fopen("studenti.txt", "r");

	if (fs == NULL) {
		printf("nemoguce otvorit datoteku");
		exit(1);
	}
	int i, j;
	int n = 0;
	char zn;
	float relbrBod;

	while ((zn = fgetc(fs)) != EOF) {
		if (zn == '\n') {               //brojanje redaka
			++n;
		}
	}
	_student* s;
	s = (_student*)malloc(n * sizeof(_student));

	for (i = 0; i < n; i++) {
		fscanf(fs, "%s %s", (s+i)->ime, (s+i)->prezime);
		fscanf(fs, "%d", &s[i].brBod);
	}
	fclose(fs);

	
	for (i = 0; i < n; i++) {
		relbrBod = (float)s[i].brBod / (float)max_bod * 100;
		printf("\nime: %s\tprezime:%s\t aps.bodovi:%d\t rel.bodovi:%f\n ", s[i].ime, s[i].prezime, s[i].brBod, relbrBod);

	
	}
	
	return 0;

}