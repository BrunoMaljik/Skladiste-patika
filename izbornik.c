#define _CRT_SECURE_NO_WARNINGS

#include "funkcije.h"
#include <stdio.h>
#include <stdlib.h>

int izbornik(const char* const ime) {

	printf("Odaberite jednu od ponudenih opcija: \n\n");
	printf("Opcija 1: Dodavanje patika:\n\n");
	printf("Opcija 2: Sortiranje patike po cijeni od najvece\n\n");
	printf("Opcija 3: Sortiranje patike po cijeni od najmanje\n\n");
	printf("Opcija 4: Ispis svih patika\n\n");
	printf("Opcija 5: Pretrazivanje patika po ID-u\n\n");
	printf("Opcija 6: Brisanje patika\n\n");
	printf("Opcija 7: Zavrsetak programa\n\n");

	int opcija = 0;
	static PATIKE* poljePatika = NULL;
	static PATIKE* pronadenePatike = NULL;

	scanf("%d", &opcija);
	system("cls");

	switch (opcija) {

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
		opcija = izlaz(poljePatika);

		break;
	default:
		opcija = 0;

	}

	return opcija;

}
