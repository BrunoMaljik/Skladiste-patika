#ifndef FUNKCIJE_H
#define FUNKCIJE_H
#include "datatype.h"

int izbornik(const char* const);
void inicijalizacija(const char* const);
void dodajPatike(const char* const);
void* ucitajPatike(const char* const);
void ispisiPatike(const PATIKE* const);
void brisanjePatika(PATIKE* const, const char* const);
void* pretrazivanje(PATIKE* const);
void zamjena(PATIKE* const, PATIKE* const);
void* sortirajCijenaMax(char*);
void ispisiSortiranoMax(const PATIKE* polje);
void* sortirajCijenaMin(char*);
void ispisiSortiranoMin(const PATIKE* polje);
#endif
