/*
  ---------------------------------------------------------------------------
  Nom du fichier : bateau_affichage.c
  Auteur(s)      : Samuel Roland, Hugo Germano, Patrick Maillard
  Date creation  : 30.05.2023

  Description    : le but du programme et non le but du laboratoire !!

  Remarque(s)    : à compléter

  Compilateur : gcc 12.3.1
  ---------------------------------------------------------------------------
*/
#include "bateau_affichage.h"
//#include "bateau.h"
#include <stdio.h>

void afficherBateau(const TaxeCalculee* taxeCalculee) {
	printf("================================================\n");

	printf("Nom : %s\n", taxeCalculee->bateau->nom);

	printf("Bateau a %s", BATEAU_TYPES[taxeCalculee->bateau->type]);

	if (taxeCalculee->bateau->type == MOTEUR)
		printf(
			" de %s",
			BATEAU_CATEGORIES[taxeCalculee->bateau->details.motorise.sousCategorie]);

	printf("\n");

	switch (taxeCalculee->bateau->type) {
		case MOTEUR:
			printf("Puissance du moteur : %" PRIu16 " CV\n",
					 taxeCalculee->bateau->details.motorise.puissanceMoteurs);
			switch (taxeCalculee->bateau->details.motorise.sousCategorie) {
				case PECHE:
					printf(
						"Poids maximum de peche : %" PRIu8 " T\n",
						taxeCalculee->bateau->details.motorise.details.peche.tonnageMax);
					break;
				case PLAISANCE:
					printf(
						"Longueur du bateau : %" PRIu8 " m\n",
						taxeCalculee->bateau->details.motorise.details.plaisance.longueur);
					printf("Nom du proprietaire : %s\n",
							 taxeCalculee->bateau->details.motorise.details.plaisance
								 .proprietaire);
					break;
			}
			break;
		case VOILIER:
			printf("Surface de la voilure : %" PRIu16 " m^2\n",
					 taxeCalculee->bateau->details.voilier.surfaceVoilure);
			break;
	}
	printf("Taxe annuelle : %g " MONNAIE "\n", taxeCalculee->taxe);

	printf("================================================\n\n");
}
