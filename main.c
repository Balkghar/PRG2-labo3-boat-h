#include "bateau.h"
#include "bateau_affichage.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	Bateau port[] = {
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

	// afficherPort(port);
	for (int i = 0; i < 7; i++) {
		afficherBateau(&port[i]);
		printf("\n\n");
	}
	return EXIT_SUCCESS;
}
