/*
  ---------------------------------------------------------------------------
  Nom du fichier : statistique.c
  Auteur(s)      : Samuel Roland, Hugo Germano, Patrick Maillard
  Date creation  : 30.05.2023

  Description    : le but du programme et non le but du laboratoire !!

  Remarque(s)    : à compléter

  Compilateur : Mingw-w64 gcc 11.2.0
  ---------------------------------------------------------------------------
*/

#include "statistique.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

// est ce qu'on met le tri dans une autre fonction ou non
double mediane(const double* tableau, size_t taille) {

	double* copieDeTableau = calloc(taille, sizeof(double));
	double valeurMediane;

	memcpy(copieDeTableau, tableau, taille * sizeof(double));

	qsort(copieDeTableau, sizeof(double), taille, comparerDouble);

	if (taille % 2) {
		valeurMediane =
			(copieDeTableau[taille / 2] + copieDeTableau[taille / 2 + 1]) / 2.0;
		free(copieDeTableau);
		return valeurMediane;
	} else {
		valeurMediane = copieDeTableau[taille / 2 + 1];
		free(copieDeTableau);
		return valeurMediane;
	}
}

double somme(const double* tableau, size_t taille) {
	double somme = 0;

	for (size_t i = 0; i < taille; ++i) somme += tableau[i];

	return somme;
}

double moyenne(const double* tableau, size_t taille) {
	return somme(tableau, taille) / (double) taille;
}

double ecartType(const double* tableau, size_t taille) {

	double valeurMoyenne = moyenne(tableau, taille);
	double sommeCarreDifference = 0;

	for (size_t i = 0; i < taille; ++i)
		sommeCarreDifference += pow(tableau[i] - valeurMoyenne, 2.0);

	return sqrt(sommeCarreDifference /= (double) taille);
}

int comparerDouble(const void* a, const void* b) {
	return (*(double*) a - *(double*) b);
}
