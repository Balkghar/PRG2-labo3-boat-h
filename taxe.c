#include "taxe.h"

Taxe calculBateauTaxe(const Bateau* bateau) {
	switch ((*bateau).type) {
		case MOTEUR:
			return TAXE_BASE_MOTEUR + calculBateauTaxeSpecifique(bateau);
		case VOILIER:
			return TAXE_BASE_VOILIER + (((*bateau).details.voilier.surfaceVoilure <
												  VOILIER_LIMITE_TAILLE_VOILE)
													 ? TAXE_VOILIER_PETITE_VOILE
													 : TAXE_VOILIER_GRANDE_VOILE);
		default:
			return 0.0;
	}
}

Taxe calculBateauTaxeSpecifique(const Bateau* bateau) {
	switch ((*bateau).details.motorise.sousCategorie) {
		case PECHE:
			return ((*bateau).details.motorise.details.peche.tonnageMax <
					  PECHE_LIMITE_TONNAGE)
						 ? TAXE_PECHE_PETIT_TONNAGE
						 : TAXE_PECHE_GRAND_TONNAGE;
		case PLAISANCE:
			return ((*bateau).details.motorise.puissanceMoteurs <
					  PLAISANCE_LIMITE_MOTEUR)
						 ? TAXE_PLAISANCE_PETIT_MOTEUR
						 : TAXE_PLAISANCE_GRAND_MOTEUR_FACTEUR *
								(*bateau).details.motorise.details.plaisance.longueur;
		default:
			return 0.0;
	}
}
