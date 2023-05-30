#include "bateau.h"
#include "bateau_affichage.h"
#include "port.h"
#include "statistique.h"
#include <stdio.h>
#include <stdlib.h>
#define PORT_TAILLE 7
int main(void) {
	Bateau port[PORT_TAILLE] = {
		//Quelques bateaux à voiles
		{.nom = "L'aventurier",
		 .type = VOILIER,
		 .details.voilier.surfaceVoilure = 140},
		{.nom = "Le roadtrip", .type = VOILIER, .details.voilier.surfaceVoilure = 200},
		{.nom = "L'infini", .type = VOILIER, .details.voilier.surfaceVoilure = 65},

		//Quelques bateaux à moteurs
		{.nom = "SaintMarin",
		 .type = MOTEUR,
		 .details.motorise = {.puissanceMoteurs = 30,
									 .sousCategorie = PECHE,
									 .details.peche.tonnageMax = 12}},
		{.nom = "Pieds dans le sable",
		 .type = MOTEUR,
		 .details.motorise = {.puissanceMoteurs = 120,
									 .sousCategorie = PECHE,
									 .details.peche.tonnageMax = 50}},
		{.nom = "Pieds dans le sable",
		 .type = MOTEUR,
		 .details.motorise = {.puissanceMoteurs = 120,
									 .sousCategorie = PLAISANCE,
									 .details.plaisance = {.longueur = 23,
																  .proprietaire = "Jean Martin"}}},
		{.nom = "Le grand large",
		 .type = MOTEUR,
		 .details.motorise = {.puissanceMoteurs = 60,
									 .sousCategorie = PLAISANCE,
									 .details.plaisance = {.longueur = 50,
																  .proprietaire = "Jeanne Milou"}}},
	};

	afficherBateauxParTaxeDecroissante(port, PORT_TAILLE);

	double test[] = {2.0, 3.0, 2.3, 4.6, 2.7};

	double moyen = moyenne(test, 5);

	double somm = somme(test, 5);

	double median = mediane(test, 5);

	double ecartTyp = ecartType(test, 5);

	printf("Moyenne : %g | Somme : %g | Médianne : %g | Écart-type : %g\n", moyen,
			 somm, median, ecartTyp);

	return EXIT_SUCCESS;
}
