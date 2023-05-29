#include "port.h"
#include "bateau_affichage.h"
#include "stdlib.h"
#include "taxe.h"
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