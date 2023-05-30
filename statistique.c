#include "statistique.h"
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double mediane(const double* tableau, size_t taille) {

	double* copieDeTableau = calloc(taille, sizeof(double));
	double valeurMediane;

	memcpy(copieDeTableau, tableau, taille * sizeof(double));

	qsort(copieDeTableau, taille, sizeof(double), comparerDouble);

	if (taille % 2) {
		valeurMediane = copieDeTableau[taille / 2];
		free(copieDeTableau);
		return valeurMediane;
	} else {
		valeurMediane =
			(copieDeTableau[taille / 2 - 1] + copieDeTableau[taille / 2]) / 2.0;
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
	if (*(double*) a > *(double*) b) return 1;
	else if (*(double*) a < *(double*) b)
		return -1;
	else
		return 0;
}
