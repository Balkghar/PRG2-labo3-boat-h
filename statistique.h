#ifndef STATISTIQUE_H
#define STATISTIQUE_H
#include <stdio.h>

//Calcul de la médiane d'un tableau de double
double mediane(const double* tab, size_t taille);

//Calcul de la somme d'un tableau de double
double somme(const double* tab, size_t taille);

//Calcul de la moyenne d'un tableau de double
double moyenne(const double* tab, size_t taille);

//Calcul de l'écart type d'un tableau de double
double ecartType(const double* tab, size_t taille);

#endif
