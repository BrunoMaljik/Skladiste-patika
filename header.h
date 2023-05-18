#pragma once
#ifndef HEADER_H
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS
typedef struct patike {
	float velicina;
	char marka[20];
	float cijena;
	int id;
} PATIKE;
int vracaBrojPatika();
void unosPodataka();
void ispisPatika();
void najjeftinije();
void najskuplje();
void sortiranje();
void brisanjePatika();
void izlaz();

#endif
