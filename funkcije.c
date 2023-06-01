#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "dataType.h"
//koncept 6



static int brojPatika = 0;
// Koncept 5
void inicijalizacija(const char* const ime) {

	FILE* fp = fopen(ime, "rb");

	if (fp == NULL) {
		fp = fopen(ime, "wb");

		fwrite(&brojPatika, sizeof(int), 1, fp);
		fclose(fp);
		printf("Kreirana datoteka patike.bin\n\n");
	}
	else {
		fclose(fp);
	}
}

void dodajPatike(const char* const ime) {
	//koncept 4
	FILE* fp = fopen(ime, "rb+");

	if (fp == NULL) {
		perror("Dodajte patike u datoteku patike.bin");
		//koncept 19
		exit(EXIT_FAILURE);
	}

	fread(&brojPatika, sizeof(int), 1, fp);
	printf("Broj unesenih patika: %d \n\n", brojPatika);

	PATIKE temp = { 0 };
	temp.id = brojPatika + 1;
	getchar();

	printf("Unesite marku patika: ");
	scanf(" %20s", temp.marka);
	getchar();

	printf("Unesite velicinu patike: ");
	scanf(" %f", &temp.velicina);
	getchar();

	printf("Unesite cijenu patika: ");
	scanf(" %f", &temp.cijena);
	getchar();

	printf("Unesite kolicinu patika: ");
	scanf(" %d", &temp.kolicina);
	getchar();

	fseek(fp, sizeof(PATIKE) * brojPatika, SEEK_CUR);
	fwrite(&temp, sizeof(PATIKE), 1, fp);
	printf("Nove patike dodane\n\n");

	rewind(fp);
	brojPatika++;

	fwrite(&brojPatika, sizeof(int), 1, fp);
	fclose(fp);
}
void* ucitajPatike(const char* const ime) {

	FILE* fp = fopen(ime, "rb");

	if (fp == NULL) {
		perror("Ucitavanje patika iz patike.bin");
		exit(EXIT_FAILURE);
	}

	fread(&brojPatika, sizeof(int), 1, fp);
	printf("Broj patika: %d\n", brojPatika);

	PATIKE* poljePatika = (PATIKE*)calloc(brojPatika, sizeof(PATIKE));
	//koncept 13

	if (poljePatika == NULL) {
		perror("Zauzimanje memorije za polje patika");
		return NULL;
	}

	fread(poljePatika, sizeof(PATIKE), brojPatika, fp);

	printf("Sve patike su uspjesno ucitane\n\n");

	return poljePatika;
}

void zamjena(PATIKE* const veci, PATIKE* const manji) {
	PATIKE temp = { 0 };
	temp = *manji;
	*manji = *veci;
	*veci = temp;
}

void brisanjePatika(PATIKE* const polje, const char* const dat) {

	if (brojPatika == 0) {
		printf("Polje patika je prazno\n");
		return;
	}

	FILE* fp = fopen(dat, "rb+");
	//koncept 16

	if (fp == NULL) {
		perror("Brisanje patika");
		exit(EXIT_FAILURE);
	}

	fseek(fp, sizeof(int), SEEK_CUR);

	int i, trazeniID; 
	//koncept 4

	printf("Unesite ID patika kojeg zelite obrisati: ");

	do {
		scanf("%d", &trazeniID);
		if (trazeniID < 1 || trazeniID > brojPatika) {
			printf("Patike s tim ID-om ne postoje!");
		}
	} while (trazeniID < 1 || trazeniID > brojPatika);

	PATIKE* poljePatika = (PATIKE*)calloc(brojPatika - 1, sizeof(PATIKE));
	//koncept 14

	int brojac = 0;

	for (i = 0; i < brojPatika; i++) {

		if (trazeniID != (polje + i)->id) {
			*(poljePatika + brojac) = *(polje + i);

			if ((poljePatika + brojac)->id > trazeniID) {
				(poljePatika + brojac)->id -= 1;
			}

			fwrite((poljePatika + brojac), sizeof(PATIKE), 1, fp);
			brojac++;
		}

	}

	free(poljePatika);
	poljePatika = NULL;
	//koncept 15

	rewind(fp);
	//koncept 17

	fwrite(&brojac, sizeof(int), 1, fp);
	fclose(fp);

	printf("Patike su uspjesno obrisane\n");

}

void* sortirajMaxCijenu(PATIKE* polje) {
	//koncept 20
	int max = -1;

	for (int i = 0; i < brojPatika - 1; i++) {

		max = i;

		for (int j = i + 1; j < brojPatika; j++) {

			if ((polje + j)->cijena > (polje + max)->cijena) {
				max = j;
			}
		}
		zamjena((polje + i), (polje + max));
	}

	return polje;
}


void ispisiSortiranoMax(const PATIKE* polje) {

	if (brojPatika == 0) {
		printf("Polje patika je prazno\n");
		return;
	}
	polje = sortirajMaxCijenu(polje);

	for (int i = 0; i < brojPatika; i++) {
		printf("ID: %d\tMarka: %s\tVelicina: %f\tCijena: %.2f\tKolicina:%d\n\n",
			(polje + i)->id,
			(polje + i)->marka,
			(polje + i)->velicina,
			(polje + i)->cijena,
			(polje + i)->kolicina);
	}
}

void* sortirajMinCijenu(PATIKE* polje) {
	int min = -1;

	for (int i = 0; i < brojPatika - 1; i++) {

		min = i;

		for (int j = i + 1; j < brojPatika; j++) {

			if ((polje + j)->cijena < (polje + min)->cijena) {
				min = j;
			}
		}
		zamjena((polje + i), (polje + min));
	}

	return polje;
}

void ispisiSortiranoMin(const PATIKE* polje) {

	if (brojPatika == 0) {
		printf("Polje patika je prazno\n");
		return;
	}
	polje = sortirajMinCijenu(polje);

	for (int i = 0; i < brojPatika; i++) {
		printf("ID: %d\tMarka: %s\tVelicina: %f\tCijena: %.2f\tKolicina:%d\n\n",
			(polje + i)->id,
			(polje + i)->marka,
			(polje + i)->velicina,
			(polje + i)->cijena,
			(polje + i)->kolicina);
	}
}

void ispisiPatike(const PATIKE* const polje) {

	if (polje == NULL) {
		printf("Polje patika je prazno");
		return;
	}

	for (int i = 0; i < brojPatika; i++) {
		printf("ID: %d\tMarka: %s \tVelicina: %f\tCijena: %.2f\tKolicina:%d\n\n",
			(polje + i)->id,
			(polje + i)->marka,
			(polje + i)->velicina,
			(polje + i)->cijena,
			(polje + i)->kolicina);
	}
}

void* pretrazivanje(PATIKE* const polje) {
	//koncept 21

	if (polje == NULL) {
		printf("Polje patika je prazno");
		return NULL;
		//koncept 11
	}
	int i, trazeniID;

	printf("Unesite ID patika koje zelite pronaci: ");
	scanf("%d", &trazeniID);

	for (i = 0; i < brojPatika; i++) {

		if (trazeniID == (polje + i)->id) {
			printf("Patike pronadene\n");

			return  (polje + i);
		}
	}

	return NULL;
}

void brisanjeDatoteke(char* fp) {

	int status;
	status = remove("patike.bin");
	//18

	if (status == 0) {
		printf("Datoteka uspjesno obrisana\n");

	}
	else {
		printf("Datoteka ne moze biti obrisana\n");
	}
	return 0;
}

int izlaz(PATIKE* polje) {

	free(polje);

	return 0;
}
