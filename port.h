#ifndef PORT_H
#define PORT_H
#include "bateau.h"
#include "taxe.h"
#include <stddef.h>

//Struct permettant de stocker la taxe calculée pour un bateau donné
typedef struct {
	Taxe taxe;
	const Bateau* bateau;
} TaxeCalculee;

//Fonction de comparaison décroissante des taxes dans TaxeCalculee, pour qsort()
int comparerTaxeDesc(const void* a, const void* b);

//Afficher tous les bateaux données en les triant par leur taxe annuelle décroissante
void afficherBateauxParTaxeDecroissante(const Bateau* bateau, size_t taille);
#endif
