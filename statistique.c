#include "statistique.h"
#include <math.h>

double mediane(double* tab, size_t taille) {
	if (taille % 2) {
		return (tab[taille / 2] + tab[taille / 2 + 1]) / 2.0;
	} else {
		return tab[taille / 2 + 1];
	}
}

double somme(double* tab, size_t taille) {
	double somme = 0;

	for (size_t i = 0; i < taille; ++i) somme += tab[i];


	return somme;
}

double moyenne(double* tab, size_t taille) { return somme(tab, taille) / taille; }

double ecartType(double* tab, size_t taille) {

	double moyenn = moyenne(tab, taille);
	double sommeDiffAuCarre = 0;

	for (size_t i = 0; i < taille; ++i) sommeDiffAuCarre += pow(tab[i] - moyenn, 2.0);


	sommeDiffAuCarre /= taille;

	return sqrt(sommeDiffAuCarre);
}