/*
  ---------------------------------------------------------------------------
  Nom du fichier : statistique.c
  Auteur(s)      : Samuel Roland, Hugo Germano, Patrick Maillard
  Date creation  : 30.05.2023

  Description    : Définition des fonctions de statistique.h

  Remarque(s)    : -

  Compilateur : gcc 12.3.1
  ---------------------------------------------------------------------------
*/

#include "statistique.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

double mediane(const double* tableau, size_t taille) {

	double* copieDeTableau = (double*) calloc(taille, sizeof(double));

	memcpy(copieDeTableau, tableau, taille * sizeof(double));

	qsort(copieDeTableau, taille, sizeof(double), comparerDouble);

	//Calcul différent si le tableau est de taille paire ou impaire
	double valeurMediane =
		taille % 2
			? copieDeTableau[taille / 2]
			: (copieDeTableau[taille / 2 - 1] + copieDeTableau[taille / 2]) / 2.0;

	free(copieDeTableau);
	return valeurMediane;
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
