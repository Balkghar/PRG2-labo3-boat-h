/*
  ---------------------------------------------------------------------------
  Nom du fichier : port.h
  Auteur(s)      : Samuel Roland, Hugo Germano, Patrick Maillard
  Date creation  : 30.05.2023

  Description    : Ce fichier contenant toutes les informations des taxes de chaque
  bateau, ainsi que la déclaration des fonctions en rapport avec l'affichage de ces
  taxes.

  Remarque(s)    : -

  Compilateur : gcc 12.3.1
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

//Afficher les statistiques pour 
void afficherStatistique(const char* texte, const double* taxe, size_t taille);

//Fonction de comparaison décroissante des taxes dans TaxeCalculee, pour qsort()
int comparerTaxeDesc(const void* a, const void* b);

//Afficher tous les bateaux données en les triant par leur taxe annuelle décroissante
void afficherBateauxParTaxeDecroissante(const Bateau* bateau, size_t taille);

//Afficher les statistiques de tous les bateaux donnés triés par type
void afficherBateauxStatistiquesParType(const Bateau* bateau, size_t taille);
#endif
