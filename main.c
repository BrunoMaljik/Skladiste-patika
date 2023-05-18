#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	int option;
	while (1) {
		system("cls");
		printf("\nUnesite broj opcije koju zelite: \n\n");
		printf("(1)Dodavanje patika.\n");
		printf("(2)Pretraga odredene patike.\n");
		printf("(3)Ispis najjeftinih patika.\n");
		printf("(4)Ispis najskupljih patika.\n");
		printf("(5)Brisanje patika.\n");
		printf("(6)Sortiranje patika.\n");
		printf("(7)Izlazak iz programa.\n\n");
		scanf("%d", &opcija);
		switch (opcija) {
		case 1:
			unosPodataka();
			break;
		case 2:
			pretragaPatika();
			break;
		case 3:
			pretragaMin();
			break;
		case 4:
			pretragaMax();
			break;

		case 5:
			brisanjePatika();
			break;

		case 6:
			sortiranje();
			break;

		case 7:
			izlaz();
			break;
		}
	}

	return 0;
}