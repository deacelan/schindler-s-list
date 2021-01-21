/*10. Napisati program koji iz datoteke èita postfiks izraz i zatim stvara stablo proraèuna. Iz
gotovog stabla proraèuna upisati u datoteku infiks izraz.*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct tree;
typedef struct tree* PositionTree;

struct stack;
typedef struct stack* PositionStack;

struct tree {
	char el[10];
	PositionTree left;
	PositionTree right;
};

struct stack {
	PositionTree stablo;
	PositionStack next;
};

PositionTree CreateNewTree();
PositionStack CreateNewStack();
int Push(PositionStack, PositionTree);
PositionTree Pop(PositionStack);
int ReadFile(PositionStack, PositionTree);
int PrintInorder(PositionTree);

int main() {
	struct stack head;
	PositionTree root = NULL;

	head.next = NULL;
	int provjera = 0;

	provjera = ReadFile(&head, root);
	if (provjera != 0) {
		printf("Greska! provjera = %d\n", provjera);
	}

	PrintInorder(head.next->stablo);

	return 0;
}
int ReadFile(PositionStack p, PositionTree s) {
	char* fileName = NULL, *buffer = NULL;
	FILE* dat = NULL;
	PositionTree st = NULL;
	int  i = 0;

	fileName = (char *)malloc(30 * sizeof(char));
	if (fileName == NULL) return -2;

	buffer = (char *)malloc(30 * sizeof(char));
	if (buffer == NULL) return -2;

	printf("Upisi ime datoteke: ");
	scanf(" %s", fileName);

	if (strchr(fileName, '.') == NULL)
		strcat(fileName, ".txt");

	dat = fopen(fileName, "r");
	if (dat == NULL) return -3;

	while (!feof(dat)) {
		memset(buffer, 0, 30);

		fscanf(dat, "%s", buffer);


		if (isdigit(buffer[0]))
		{
			st = CreateNewTree();
			if (st == NULL) return -1;

			strcpy(st->el, buffer);
			i = Push(p, st);
			if (i != 0) return -5;

		}
		else if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/')
		{
			st = CreateNewTree();
			if (st == NULL) return -1;

			strcpy(st->el, buffer);
			st->right = Pop(p);
			st->left = Pop(p);

			i = Push(p, st);
		}
		else
			continue;
	}

	fclose(dat);
	free(fileName);
	free(buffer);

	return 0;
}

int PrintInorder(PositionTree s) {
	if (s != NULL) {
		PrintInorder(s->left);
		printf(" %s ", s->el);
		PrintInorder(s->right);
	}
	return 0;
}

PositionTree CreateNewTree() {
	PositionTree q = NULL;
	q = (PositionTree)malloc(sizeof(struct tree));
	if (q == NULL) return q;

	q->left = q->right = NULL;
	return q;
}

PositionStack CreateNewStack() {
	PositionStack q = NULL;
	q = (PositionStack)malloc(sizeof(struct stack));
	if (q == NULL) return q;

	q->next = q->stablo = NULL;
	return q;
}

int Push(PositionStack p, PositionTree s) {
	if (p == NULL || s == NULL) return -6;

	PositionStack q = NULL;
	q = CreateNewStack();
	if (q == NULL) return -2;

	q->stablo = s;

	q->next = p->next;
	p->next = q;

	return 0;
}

PositionTree Pop(PositionStack p) {
	if (p == NULL) return NULL;
	if (p->next == NULL) return NULL;

	PositionStack temp = NULL;
	PositionTree stablo = NULL;

	temp = p->next;
	stablo = temp->stablo;

	p->next = temp->next;
	free(temp);
	return (stablo);
}