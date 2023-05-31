/*
  ---------------------------------------------------------------------------
  Nom du fichier : bateau_affichage.c
  Auteur(s)      : Samuel Roland, Hugo Germano, Patrick Maillard
  Date creation  : 30.05.2023

  Description    : Définition de la fonction de bateau_affichage.h

  Remarque(s)    : -

  Compilateur : gcc 12.3.1
  ---------------------------------------------------------------------------
*/
#include "bateau_affichage.h"
//#include "bateau.h"
#include <stdio.h>

void afficherBateau(const TaxeCalculee* taxeCalculee) {
	printf("================================================\n");

	printf("Nom : %s\n", taxeCalculee->BATEAU->nom);

	printf("Bateau a %s", BATEAU_TYPES[taxeCalculee->BATEAU->type]);

	if (taxeCalculee->BATEAU->type == MOTEUR)
		printf(
			" de %s",
			BATEAU_CATEGORIES[taxeCalculee->BATEAU->details.motorise.sousCategorie]);

	printf("\n");

	switch (taxeCalculee->BATEAU->type) {
		case MOTEUR:
			printf("Puissance du moteur : %" PRIu16 " CV\n",
					 taxeCalculee->BATEAU->details.motorise.puissanceMoteurs);
			switch (taxeCalculee->BATEAU->details.motorise.sousCategorie) {
				case PECHE:
					printf(
						"Poids maximum de peche : %" PRIu8 " T\n",
						taxeCalculee->BATEAU->details.motorise.details.peche.tonnageMax);
					break;
				case PLAISANCE:
					printf(
						"Longueur du bateau : %" PRIu8 " m\n",
						taxeCalculee->BATEAU->details.motorise.details.plaisance.longueur);
					printf("Nom du proprietaire : %s\n",
							 taxeCalculee->BATEAU->details.motorise.details.plaisance
								 .proprietaire);
					break;
			}
			break;
		case VOILIER:
			printf("Surface de la voilure : %" PRIu16 " m^2\n",
					 taxeCalculee->BATEAU->details.voilier.surfaceVoilure);
			break;
	}
	printf("Taxe annuelle : %g " MONNAIE "\n", taxeCalculee->taxe);

	printf("================================================\n\n");
}
