#define _CRT_SECURE_NO_WARNINGS

#include "funkcije.h"
#include <stdio.h>
#include <stdlib.h>
#include "dataType.h"

int izbornik(const char* const ime) {  
//8

	printf("Odaberite jednu od opcija: \n\n");
	printf(" 1: Dodajte nove patike:\n\n");
	printf(" 2: Sortiranje patike po cijeni od najvece\n\n");
	printf(" 3: Sortiranje patike po cijeni od najmanje\n\n");
	printf(" 4: Ispis unesenih patika\n\n");
	printf(" 5: Pretrazivanje patika po ID-u\n\n");
	printf(" 6: Brisanje unesenih patika\n\n");
	printf(" 7: Zatvorite program\n\n");

	int odabir = 0;
	static PATIKE* poljePatika = NULL;
	static PATIKE* pronadenePatike = NULL;
//9

	scanf("%d", &odabir);
	system("cls");

	switch (odabir) {

	case 1:

		dodajPatike(ime);
		break;

	case 2:
		if (poljePatika != NULL) {
			free(poljePatika);
			poljePatika = NULL;
		}

		poljePatika = (PATIKE*)ucitajPatike(ime);
		ispisiSortiranoMax(poljePatika);

		break;


	case 3:
		if (poljePatika != NULL) {
			free(poljePatika);
			poljePatika = NULL;
		}

		poljePatika = (PATIKE*)ucitajPatike(ime);
		ispisiSortiranoMin(poljePatika);

		break;

	case 4:
		if (poljePatika != NULL) {
			free(poljePatika);
		}

		poljePatika = (PATIKE*)ucitajPatike(ime);

		ispisiPatike(poljePatika);
		break;

	case 5:
		if (poljePatika != NULL) {
			free(poljePatika);
		}

		poljePatika = (PATIKE*)ucitajPatike(ime);

		pronadenePatike = (PATIKE*)pretrazivanje(poljePatika);

		if (pronadenePatike != NULL) {
			printf("ID: %d\n", pronadenePatike->id);
			printf("Marka: %s\n", pronadenePatike->marka);
			printf("Velicina: %f\n", pronadenePatike->velicina);
			printf("Cijena: %f\n", pronadenePatike->cijena);
			printf("Kolicina: %d\n", pronadenePatike->kolicina);
		}
		else {
			printf("Ne postoje patike s tim ID-om");
		}
		break;

	case 6:
		if (poljePatika != NULL) {
			free(poljePatika);
			poljePatika = NULL;
		}

		poljePatika = (PATIKE*)ucitajPatike(ime);

		brisanjePatika(poljePatika, ime);
		break;

	case 7:
		odabir = izlaz(poljePatika);

		break;
	default:
		odabir = 0;

	}

	return odabir;

}
