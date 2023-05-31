/*
  ---------------------------------------------------------------------------
  Nom du fichier : port.c
  Auteur(s)      : Samuel Roland, Hugo Germano, Patrick Maillard
  Date creation  : 30.05.2023
  
  Description    : Définition des fonctions de port.h

  Remarque(s)    : -

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

void afficherStatistique(const char* texte, const double* taxe, size_t taille) {
	printf("================================================\n");


	printf("Statistiques pour les taxes sur les bateaux de type %s\n\n", texte);

	printf("Moyenne    : %.2f " MONNAIE "\n", moyenne(taxe, taille));
	printf("Mediane    : %.2f " MONNAIE "\n", mediane(taxe, taille));
	printf("Somme      : %.2f " MONNAIE "\n", somme(taxe, taille));
	printf("Ecart-type : %.2f " MONNAIE "\n", ecartType(taxe, taille));

	printf("\n================================================\n\n");
}

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

	size_t tailleTaxeBateauVoilier = 0;
	size_t tailleTaxeBateauPeche = 0;
	size_t tailleTaxeBateauPlaisance = 0;

	//calcul de la taille des tableaux pour les taxes pour chaque type de bateau
	for (size_t i = 0; i < taille; i++) {
		switch (bateau[i].type) {
			case MOTEUR:
				switch (bateau[i].details.motorise.sousCategorie) {
					case PLAISANCE:
						++tailleTaxeBateauPlaisance;
						break;
					case PECHE:
						++tailleTaxeBateauPeche;
						break;
				}
				break;
			case VOILIER:
				++tailleTaxeBateauVoilier;
				break;
		}
	}

	double* taxeBateauVoilier = calloc(tailleTaxeBateauVoilier, sizeof(double));
	double* taxeBateauPeche = calloc(tailleTaxeBateauPeche, sizeof(double));
	double* taxeBateauPlaisance = calloc(tailleTaxeBateauPlaisance, sizeof(double));

	size_t indexVoilier = 0;
	size_t indexPeche = 0;
	size_t indexPlaisance = 0;

	//calcul des taxes pour chaque type de bateaux
	for (size_t i = 0; i < taille; i++) {
		switch (bateau[i].type) {
			case MOTEUR:
				switch (bateau[i].details.motorise.sousCategorie) {
					case PLAISANCE:
						taxeBateauPlaisance[indexPlaisance] = calculBateauTaxe(&bateau[i]);
						++indexPlaisance;
						break;
					case PECHE:
						taxeBateauPeche[indexPeche] = calculBateauTaxe(&bateau[i]);
						++indexPeche;
						break;
				}
				break;
			case VOILIER:
				taxeBateauVoilier[indexVoilier] = calculBateauTaxe(&bateau[i]);
				++indexVoilier;
				break;
		}
	}

	afficherStatistique("plaisance", taxeBateauPlaisance, tailleTaxeBateauPlaisance);
	afficherStatistique("peche", taxeBateauPeche, tailleTaxeBateauPeche);
	afficherStatistique("voilier", taxeBateauVoilier, tailleTaxeBateauVoilier);

	free(taxeBateauPlaisance);
	free(taxeBateauPeche);
	free(taxeBateauVoilier);
}


