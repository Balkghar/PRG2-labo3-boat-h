/*
  ---------------------------------------------------------------------------
  Nom du fichier : port.h
  Auteur(s)      : Samuel Roland, Hugo Germano, Patrick Maillard
  Date creation  : 30.05.2023

  Description    : le but du programme et non le but du laboratoire !!

  Remarque(s)    : à compléter

  Compilateur : Mingw-w64 gcc 11.2.0
  ---------------------------------------------------------------------------
*/

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
