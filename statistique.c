#include "statistique.h"
#include <math.h>

double mediane(const double* tab, size_t taille) {
	if (taille % 2) {
		return (tab[taille / 2] + tab[taille / 2 + 1]) / 2.0;
	} else {
		return tab[taille / 2 + 1];
	}
}

double somme(const double* tab, size_t taille) {
	double somme = 0;

	for (size_t i = 0; i < taille; ++i) somme += tab[i];

	return somme;
}

double moyenne(const double* tab, size_t taille) {
	return somme(tab, taille) / (double) taille;
}

double ecartType(const double* tab, size_t taille) {

	double valeurMoyenne = moyenne(tab, taille);
	double sommeCarreDifference = 0;

	for (size_t i = 0; i < taille; ++i)
		sommeCarreDifference += pow(tab[i] - valeurMoyenne, 2.0);

	return sqrt(sommeCarreDifference /= (double) taille);
}
