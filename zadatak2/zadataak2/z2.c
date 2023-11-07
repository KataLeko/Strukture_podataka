#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct osoba*Position;
struct osoba {
	char ime[20], prezime[20];
	int god_r;
	Position Next;

};

int insert(Position);
int insert(Position);
int print(Position);
Position FindLast(Position);
Position Find(Position);
Position FindPrev(Position);

int Delete(Position);

int main(){
	struct osoba head;
	head.Next = NULL;

	insert(&head);
	insert(&head);
	print(head.Next);


	return 0;

}

int insert(Position P) {

	Position temp;
	temp = (Position)malloc(sizeof(struct osoba));
	printf("Unesite ime, prezime i godinu rodjenja: ");
	scanf("%s %s %d", temp->ime, temp->prezime, &temp->god_r);
	temp->Next = P->Next;
	P->Next = temp;

	return 0;
}


int print(Position P){
	
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
Position FindLast(Position P) {
	while (NULL != P->Next)
		P = P->Next;
	return P;
}

Position Find(Position P) {
	char prez[20];
	if (NULL == P->Next) {
		P = NULL;
	}
	else {
		printf("\n Unesi prezime osobe koju zelis pronaci: ");
		scanf(" %s", prez);
		while(strcmpi (P->Next->prezime, prez) != 0 && P->Next->Next != NULL)
			P = P->Next;
		if (strcmpi(P->Next->prezime, prez) != 0)
			P = NULL;
	}
	return P; 

}
int Delete(Position P) {
	Position prev;

	prev = FindPrev(P);

	if (NULL != prev) {
		P = prev->Next;
		prev->Next = P->Next;
		printf("\nOsoba %s %s %d je obrisana", P->ime, P->prezime, P->god_r);
		free(P);
	}
	else {

		printf("\nOsoba ne postoji u listi.");
	}
	return 0;
}