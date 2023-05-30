/*
  ---------------------------------------------------------------------------
  Nom du fichier : port.c
  Auteur(s)      : Samuel Roland, Hugo Germano, Patrick Maillard
  Date creation  : 30.05.2023
  
  Description    : le but du programme et non le but du laboratoire !!

  Remarque(s)    : à compléter

  Compilateur : gcc 12.3.1
  ---------------------------------------------------------------------------
*/


#include "port.h"
#include "bateau.h"
#include "bateau_affichage.h"
#include "statistique.h"
#include "stdlib.h"
#include "taxe.h"
#include <stddef.h>
#include <stdio.h>

void afficherStatistique(const char* texte, const double* taxe, size_t taille);

int comparerTaxeDesc(const void* a, const void* b) {
	return (int) ((*(TaxeCalculee*) b).taxe - (*(TaxeCalculee*) a).taxe);
}

void afficherBateauxParTaxeDecroissante(const Bateau* bateau, size_t taille) {
	//Calculer les taxes pour chaque bateau
	TaxeCalculee* taxesCalculees =
		(TaxeCalculee*) calloc(taille, sizeof(TaxeCalculee));

	for (size_t i = 0; i < taille; i++) {
		taxesCalculees[i].taxe = calculBateauTaxe(&bateau[i]);
		taxesCalculees[i].bateau = &bateau[i];
	}

	//Trier les bateaux par la taxe, dans l'ordre décroissant
	qsort(taxesCalculees, taille, sizeof(TaxeCalculee), comparerTaxeDesc);

	//Afficher les bateaux
	for (size_t i = 0; i < taille; i++) { afficherBateau(&taxesCalculees[i]); }

	free(taxesCalculees);
}

void afficherBateauxStatistiquesParType(const Bateau* bateau, size_t taille) {

	double* taxeBateauPlaisance = calloc(0, sizeof(double));
	size_t tailleTaxeBateauPlaisance = 0;
	double* taxeBateauPeche = calloc(0, sizeof(double));
	size_t tailleTaxeBateauPeche = 0;
	double* taxeBateauVoilier = calloc(0, sizeof(double));
	size_t tailleTaxeBateauVoilier = 0;


	for (size_t i = 0; i < taille; i++) {
		switch (bateau[i].type) {
			case MOTEUR:
				switch (bateau[i].details.motorise.sousCategorie) {
					case PLAISANCE:
						++tailleTaxeBateauPlaisance;
						taxeBateauPlaisance =
							realloc(taxeBateauPlaisance,
									  tailleTaxeBateauPlaisance * sizeof(double));
						taxeBateauPlaisance[tailleTaxeBateauPlaisance - 1] =
							calculBateauTaxe(&bateau[i]);
						break;
					case PECHE:
						++tailleTaxeBateauPeche;
						taxeBateauPeche = realloc(taxeBateauPeche,
														  tailleTaxeBateauPeche * sizeof(double));
						taxeBateauPeche[tailleTaxeBateauPeche - 1] =
							calculBateauTaxe(&bateau[i]);
						break;
				}
				break;
			case VOILIER:
				++tailleTaxeBateauVoilier;
				taxeBateauVoilier =
					realloc(taxeBateauVoilier, tailleTaxeBateauVoilier * sizeof(double));
				taxeBateauVoilier[tailleTaxeBateauVoilier - 1] =
					calculBateauTaxe(&bateau[i]);
				break;
		}
	}
	afficherStatistique("plaisance", taxeBateauPlaisance, tailleTaxeBateauPlaisance);
	afficherStatistique("peche", taxeBateauPeche, tailleTaxeBateauPeche);
	afficherStatistique("voilier", taxeBateauVoilier, tailleTaxeBateauVoilier);
}

void afficherStatistique(const char* texte, const double* taxe, size_t taille) {
	printf("================================================\n");


	printf("Statistiques sur les bateaux de type %s\n\n", texte);

	double valeurMoyenne = moyenne(taxe, taille);
	double valeurMediane = mediane(taxe, taille);
	double valeurSomme = somme(taxe, taille);
	double valeurEcartType = ecartType(taxe, taille);

	printf("Moyenne    : %g " MONNAIE "\n", valeurMoyenne);
	printf("Mediane    : %g " MONNAIE "\n", valeurMediane);
	printf("Somme      : %g " MONNAIE "\n", valeurSomme);
	printf("Ecart-type : %g " MONNAIE "\n", valeurEcartType);

	printf("\n================================================\n\n");
}
