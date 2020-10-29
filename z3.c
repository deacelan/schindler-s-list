﻿/*
2.Definirati strukturu osoba(ime, prezime, godina roðenja) i napisati program koji :
a) dinamièki dodaje novi element na poèetak liste,
b) ispisuje listu,
c) dinamièki dodaje novi element na kraj liste,
d) pronalazi element u listi(po prezimenu),
e) briše odreðeni element iz liste,
U zadatku se ne smiju koristiti globalne varijable.

3. Prethodnom zadatku dodati funkcije :
a) dinamički dodaje novi element iza određenog elementa,
b) dinamički dodaje novi element ispred određenog elementa,
c) sortira listu po prezimenima osoba,
d) upisuje listu u datoteku,
e) čita listu iz datoteke.*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define EXIT_SUCCESS 1
#define MAX_NAME (256)

struct _person;
typedef struct _person *Position;
typedef struct _person {
	char firstName[MAX_NAME];
	char lastName[MAX_NAME];
	int birthYear;
	Position next;
}Person;

Position createStudent(char *firstName, char *lastName, int birthYear);
void insertAfter(Position where, Position what);
void insertBefore(Position where, Position what);
void printList(Position head);
Position findElement(Position q, char *lN);
Position findLastName(Position p, char *lastN);
void deleteElement(Position p, char *lastN);
void insertAfterElement(Position where, Position what, char *lastN);
void insertBeforeElement(Position where, Position what, char *lastN);

int main(void) {
	Person head;
	Position p = NULL;

	char firstName[MAX_NAME] = { 0 };
	char lastName[MAX_NAME] = { 0 };
	int birthYear = 0;
	head.next = NULL;




	printf("Please insert person:\r\n");

	printf("First name:\t");
	scanf("%s", firstName);

	printf("Last name:\t");
	scanf("%s", lastName);

	printf("Birth year:\t");
	scanf("%d", &birthYear);

	p = createStudent(firstName, lastName, birthYear);
	insertAfter(&head, p);
	insertBefore(&head, p);






	return EXIT_SUCCESS;
}

Position createStudent(char *firstName, char *lastName, int birthYear) {
	Position p = NULL;

	p = (Position)malloc(sizeof(Person));

	if (!p) {
		printf("Memory allocation failed!\r\n");
		return NULL;
	}
	strcpy(p->firstName, firstName);
	strcpy(p->lastName, lastName);
	p->birthYear = birthYear;
	return p;
}

void insertAfter(Position where, Position what) {
	what->next = where->next;
	where->next = what;
}

void printList(Position head) {
	Position p = NULL;

	printf("List content:\r\n");

	for (p = head->next; p != NULL; p = p->next) {
		printf("\t%s %s %d\r\n", p->firstName, p->lastName, p->birthYear);
		p = p->next;
	}

	printf("\r\n");
}

void insertBefore(Position where, Position what) {
	while (where->next != NULL) {
		where = where->next;
	}
	insertAfter(where, what);
}

Position findElement(Position q, char *lN) {
	while (q->next != NULL && strcmp(q->lastName, lN)) {
		q = q->next;
	}
	return q;
}
Position findLastName(Position p, char *lastN) {
	Position last = p;
	p = p->next;

	while (p->next != NULL && strcmp(p->lastName, lastN)) {
		last = p;
		p = p->next;
	}
	if (p->next == NULL) {
		printf("Doesn't exist.\r\n");
		return NULL;
	}
	return last;
}

void deleteElement(Position p, char *lastN) {
	Position last;
	last = findLastName(p, lastN);

	if (last != NULL) {
		p = last->next;
		last->next = p->next;
		free(p);
	}

}


void insertAfterElement(Position where, Position what,char *lastN) {
	Position last;
	last = findLastName(where, lastN);

	what->next = where->next;
	where->next = what;
}

void insertBeforeElement(Position where, Position what,char *lastN) {
	Position last;
	last = findLastName(where, lastN);

	while (where->next != NULL) {
		where = where->next;
	}
	insertAfter(where, what);

}

void sortLastName(Position p, char *lastName) {

}