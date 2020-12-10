#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct cvor *Stog;
typedef struct red *Red;
struct cvor {
	int el;
	Stog next;
};

struct red {
	int El;
	Red next;
};


void pushStack(int el, Stog S);
void printStack(Stog S);
void popStack(Stog S);

void pushRow(int El, Red R);
void printRow(Red R);
void popRow(Red R);



void pushRow(int El, Red R) {
	Red q;
	q = (Red)malloc(sizeof(struct red));
	q->El = El;
	while (R->next != NULL) {
		R = R->next;
	}
	q->next = R->next;
	R->next = q;
}

void printRow(Red R) {
	while (R != NULL) {
		printf("%d ", R->El);
		R = R->next;
	}
}

void popRow(Red R) {
	Red tmp;
	tmp = R->next;
	R->next = tmp->next;
	free(tmp);
}

void popStack(Stog S) {
	int x;
	Stog temp;
	if (S->next != NULL) {
		x = S->next->el;
		temp = S->next;
		S->next = temp->next;
		free(temp);
	}

}

void pushStack(int el, Stog S) {
	Stog q;
	q = (Stog)malloc(sizeof(struct cvor));
	q->el = el;
	q->next = S->next;
	S->next = q;
}

void printStack(Stog S) {
	while (S != NULL) {
		printf("%d ", S->el);
		S = S->next;
	}
}

int main(void)
{
	struct cvor head;
	head.next = NULL;
	int i, n, r, s, a;
	printf("\rKoliko brojeva ce biti u stogu? ");
	scanf(" %d", &n);

	printf("\rKoliko brojeva ce biti u redu? ");
	scanf(" %d", &r);

	for (i = 0; i < n; i++) {
		s = rand() % 100 + 10;
		pushStack(s, &head);
	}
	printf("Stog: ");
	printStack(head.next);
	printf("\r\nStog: ");
	popStack(&head);
	printStack(head.next);
	

	struct red Head;
	Head.next = NULL;
	

	for (i = 0; i < r; i++) {
		a = rand() % 100 + 10;
		pushRow(a, &Head);
	}
	printf("\r\nRed: ");
	printRow(Head.next);
	printf("\r\nRed: ");
	popRow(&Head);
	printRow(Head.next);

	return 1;
}