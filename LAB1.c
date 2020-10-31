/*1. Napisati program koji prvo pro�ita koliko redaka ima datoteka, tj. koliko ima studenata
zapisanih u datoteci. Nakon toga potrebno je dinami�ki alocirati prostor za niz struktura
studenata (ime, prezime, bodovi) i u�itati iz datoteke sve zapise. Na ekran ispisati ime,
prezime,apsolutni i relativni broj bodova.
Napomena: Svaki redak datoteke sadr�i ime i prezime studenta, te broj bodova na kolokviju.
relatvan_br_bodova = br_bodova/max_br_bodova*100 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX (20)
#define MAX_ROW (100)

typedef struct _student
{
	int bod;
	char ime[MAX];
	char prezime[MAX];
} student;

int brojRedova(char[MAX]);

int main() {
	float aps;
	int br = 0, i = 0, max = 0;
	char fileName[MAX] = "studenti.txt";
	student S;
	FILE *fp;
	student* niz = NULL;

	br = brojRedova(fileName);
	niz = (student*)malloc(br * sizeof(student));

	fp = fopen("studenti.txt", "r");


	while (!feof(fp))
	{
		fscanf(fp, "%d %s %s", &S.bod, S.ime, S.prezime);
		niz[i] = S;
		if (S.bod >= max) max = S.bod;
		i++;
	}

	for (i = 0; i < br; i++) {
		aps = (float)niz[i].bod / max * 100;

		printf("%d %s %s - %.2f\n", niz[i].bod, niz[i].ime, niz[i].prezime, aps);
	}

	fclose(fp);

	return 0;
}

int brojRedova(char fileName[MAX])
{
	int br = 0;
	char red[MAX_ROW];

	FILE *fp;
	fp = fopen(fileName, "r");

	while (fgets(red, 100, fp)) {
		br++;
	}

	fclose(fp);
	return br;
}
