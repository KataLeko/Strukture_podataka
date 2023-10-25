#include <stdio.h>
#include <stdlib.h>

typedef struct osoba*Position;
struct osoba {
	char ime[20], prezime[20];
	int god_r;
	Position Next;

};

int UnosP(Position);
int UnosP(Position);
int Ispis(Position);
int main(){
	struct osoba head;
	head.Next = NULL;

	UnosP(&head);
	UnosP(&head);
	Ispis(head.Next);


	return 0;

}

int UnosP(Position P) {

	Position temp;
	temp = (Position)malloc(sizeof(struct osoba));
	printf("Unesite ime, prezime i godinu rodjenja: ");
	scanf("%s %s %d", temp->ime, temp->prezime, &temp->god_r);
	temp->Next = P->Next;
	P->Next = temp;

	return 0;
}


int Ispis(Position P){
	
	if (P == NULL) {
		printf("\nLista je prazna!\n");

	}
	else {
		while (P != NULL) {
			printf("\n %s %s %d", P->ime, P->prezime, P->god_r);
			P = P->Next;
		}
	}

	return 0;
}