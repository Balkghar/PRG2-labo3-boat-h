/*
  ---------------------------------------------------------------------------
  Nom du fichier : port.c
  Auteur(s)      : Samuel Roland, Hugo Germano, Patrick Maillard
  Date creation  : 30.05.2023
  
  Description    : le but du programme et non le but du laboratoire !!

  Remarque(s)    : à compléter

  Compilateur : Mingw-w64 gcc 11.2.0
  ---------------------------------------------------------------------------
*/


#include "port.h"
#include "bateau_affichage.h"
#include "stdlib.h"
//#include "taxe.h"
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