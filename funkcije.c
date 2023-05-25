#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "dataType.h"

static int brojPatika = 0;

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

	FILE* fp = fopen(ime, "rb+");

	if (fp == NULL) {
		perror("Dodavanje patika u datoteku patike.bin");
		exit(EXIT_FAILURE);
	}

	fread(&brojPatika, sizeof(int), 1, fp);
	printf("Broj patika: %d \n\n", brojPatika);

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
