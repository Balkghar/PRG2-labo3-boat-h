/*
  ---------------------------------------------------------------------------
  Nom du fichier : main.c
  Auteur(s)      : Samuel Roland, Hugo Germano, Patrick Maillard
  Date creation  : 30.05.2023

  Description    : le but du programme et non le but du laboratoire !!

  Remarque(s)    : à compléter

  Compilateur : gcc 12.3.1
  ---------------------------------------------------------------------------
*/

#include "bateau.h"
#include "port.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	Bateau port[] = {
		//Quelques bateaux à voiles
		{.nom = "L'aventurier",
		 .type = VOILIER,
		 .details.voilier.surfaceVoilure = 250},
		{.nom = "Le roadtrip", .type = VOILIER, .details.voilier.surfaceVoilure = 200},
		{.nom = "L'infini", .type = VOILIER, .details.voilier.surfaceVoilure = 65},

		//Quelques bateaux à moteurs
		{.nom = "SaintMarin",
		 .type = MOTEUR,
		 .details.motorise = {.puissanceMoteurs = 30,
									 .sousCategorie = PECHE,
									 .details.peche.tonnageMax = 12}},
		{.nom = "Le sympathique",
		 .type = MOTEUR,
		 .details.motorise = {.puissanceMoteurs = 100,
									 .sousCategorie = PECHE,
									 .details.peche.tonnageMax = 20}},
		{.nom = "Pieds dans le sable",
		 .type = MOTEUR,
		 .details.motorise = {.puissanceMoteurs = 120,
									 .sousCategorie = PECHE,
									 .details.peche.tonnageMax = 50}},
		{.nom = "Pieds dans le sable",
		 .type = MOTEUR,
		 .details.motorise = {.puissanceMoteurs = 100,
									 .sousCategorie = PLAISANCE,
									 .details.plaisance = {.longueur = 23,
																  .proprietaire = "Jean Martin"}}},
		{.nom = "Marin de Troie",
		 .type = MOTEUR,
		 .details.motorise = {.puissanceMoteurs = 200,
									 .sousCategorie = PLAISANCE,
									 .details.plaisance = {.longueur = 12,
																  .proprietaire = "Jean Martin"}}},
		{.nom = "Le grand large",
		 .type = MOTEUR,
		 .details.motorise = {.puissanceMoteurs = 60,
									 .sousCategorie = PLAISANCE,
									 .details.plaisance = {.longueur = 50,
																  .proprietaire = "Jeanne Milou"}}},
	};

	const size_t TAILLE_PORT = sizeof(port) / sizeof(Bateau);
	printf("Affichage des %" PRIuMAX " bateaux du port:\n\n", TAILLE_PORT);
	afficherBateauxParTaxeDecroissante(port, TAILLE_PORT);

	printf("\nStatistiques sur différents types de bateau :\n\n");

	afficherBateauxStatistiquesParType(port, TAILLE_PORT);

	return EXIT_SUCCESS;
}
