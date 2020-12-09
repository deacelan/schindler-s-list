/*5. Za dvije sortirane liste L1 i L2 (mogu se proèitati iz datoteke ili unijeti ruèno, bitno je
samo da su sortirane), napisati program koji stvara novu vezanu listu tako da raèuna:
a) L1?L2, (unija)
b) L1?L2. (presjek)
Liste osim pokazivaèa na slijedeæu strukturu imaju i jedan cjelobrojni element, po
kojem su sortirane.*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct cvor *Pozicija;

struct cvor {
	int  el;
	Pozicija next;
};

void SortiraniUnos(int x, Pozicija P);
void Ispis(Pozicija P);
void unija(Pozicija P1, Pozicija P2, Pozicija U);
void unos(int x, Pozicija P);
void presjek(Pozicija P1, Pozicija P2, Pozicija P);

int main()
{
	struct cvor head;
	struct cvor Head;
	head.next = NULL;
	Head.next = NULL;

	struct cvor Unija;
	Unija.next = NULL;

	struct cvor Presjek;
	Presjek.next = NULL;

	SortiraniUnos(2, &head);
	SortiraniUnos(10, &head);
	SortiraniUnos(4, &head);
	SortiraniUnos(7, &head);
	SortiraniUnos(5, &head);
	Ispis(head.next);

	printf("\r\n");

	SortiraniUnos(4, &Head);
	SortiraniUnos(1, &Head);
	SortiraniUnos(7, &Head);
	SortiraniUnos(11, &Head);
	SortiraniUnos(6, &Head);
	Ispis(Head.next);

	printf("\r\nUnija: ");
	unija(&head, &Head, &Unija);
	Ispis(Unija.next);

	printf("\r\nPresjek: ");
	presjek(&head, &Head, &Presjek);
	Ispis(Presjek.next);


	return 0;
}

void SortiraniUnos(int x, Pozicija P) {
	Pozicija q;
	while (P->next != NULL && P->next->el < x)
		P = P->next;
	q = (Pozicija)malloc(sizeof(struct cvor));

	q->el = x;
	q->next = P->next;
	P->next = q;

}

void unos(int x, Pozicija P) {
	Pozicija q;
	q = (Pozicija)malloc(sizeof(struct cvor));
	q->el = x;
	q->next = P->next;
	P->next = q;
}

void Ispis(Pozicija P) {
	while (P != NULL) {
		printf("%d ", P->el);
		P = P->next; 
	}
}

void unija(Pozicija P1, Pozicija P2, Pozicija U) {
	Pozicija temp;
	
	while (P1 != NULL && P2 != NULL) {
		if (P1->el < P2->el) {
			unos(P1->el, U);
			P1 = P1->next;
		}
		else if (P1->el > P2->el) {
			unos(P2->el, U);
			P2 = P2->next;	
		}

		else {
			unos(P1->el, U);
			P1 = P1->next;
			P2 = P2->next; 
		}
	}
	if (P1 != NULL) temp = P1;
	else temp = P2;
	while (temp != NULL) {
		unos(temp->el, U);
		temp = temp->next;
	}
}

void presjek(Pozicija P1, Pozicija P2, Pozicija P) {
	while (P1 != NULL && P2 != NULL) {
		if (P1->el < P2->el)
			P1 = P1->next;
		else if (P1->el > P2->el)
			P2 = P2->next;
		else {
			unos(P1->el, P);
			P1 = P1->next;
			P2 = P2->next;
		}
	}

}