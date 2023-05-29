#include "taxe.h"

double calculBeateauTaxe(Bateau bateau) {
	switch (bateau.type) {
		case MOTEUR:
			return TAXE_BASE_MOTEUR + calculBateauMoteurTaxe(bateau);
		case VOILIER:
			return TAXE_BASE_VOILIER + calculBateauVoilierTaxe(bateau);
		default:
			return 0.0;
	}
}
double calculBateauMoteurTaxe(Bateau bateau) {
	switch (bateau.details.motorise.sousCategorie) {
		case PECHE:
			return calculBateauMoteurPecheTaxe(bateau);
		case PLAISANCE:
			return calculBateauMoteurPlaisanceTaxe(bateau);
		default:
			return 0.0;
	}
}
double calculBateauMoteurPecheTaxe(Bateau bateau) {
	if (bateau.details.motorise.details.peche.tonnageMax < PECHE_LIMITE_TONNAGE) {
		return TAXE_PECHE_PETIT_TONNAGE;
	} else {
		return TAXE_PECHE_GRAND_TONNAGE;
	}
}
double calculBateauMoteurPlaisanceTaxe(Bateau bateau) {
	if (bateau.details.motorise.puissanceMoteurs < PLAISANCE_LIMITE_MOTEUR) {
		return TAXE_PLAISANCE_PETIT_MOTEUR;
	} else {
		return TAXE_PLAISANCE_GRAND_MOTEUR_FACTEUR *
				 bateau.details.motorise.details.plaisance.longueur;
	}
}

double calculBateauVoilierTaxe(Bateau bateau) {
	if (bateau.details.voilier.surfaceVoilure < VOILIER_LIMITE_TAILLE_VOILE) {
		return TAXE_VOILIER_PETITE_VOILE;
	} else {
		return TAXE_VOILIER_GRANDE_VOILE;
	}
}