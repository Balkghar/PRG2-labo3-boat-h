/*
  ---------------------------------------------------------------------------
  Nom du fichier : taxe.h
  Auteur(s)      : Samuel Roland, Hugo Germano, Patrick Maillard
  Date creation  : 30.05.2023
  
  Description    : le but du programme et non le but du laboratoire !!

  Remarque(s)    : à compléter

  Compilateur : Mingw-w64 gcc 11.2.0
  ---------------------------------------------------------------------------
*/

#ifndef TAXE_H
#define TAXE_H
#include "bateau.h"
//#include "inttypes.h"
typedef double Taxe;
//Constantes sur les taxes annuelles en euros
#define MONNAIE "Euros"

#define TAXE_BASE_VOILIER 50
#define TAXE_BASE_MOTEUR 100

#define VOILIER_LIMITE_TAILLE_VOILE 200//200m^2
#define TAXE_VOILIER_PETITE_VOILE 0
#define TAXE_VOILIER_GRANDE_VOILE 25

#define PECHE_LIMITE_TONNAGE 20//20 tonnes
#define TAXE_PECHE_PETIT_TONNAGE 0
#define TAXE_PECHE_GRAND_TONNAGE 100

#define PLAISANCE_LIMITE_MOTEUR 100//100 CV
#define TAXE_PLAISANCE_PETIT_MOTEUR 50
#define TAXE_PLAISANCE_GRAND_MOTEUR_FACTEUR 15//15 par mètre de la longueur

// fonction de calcul des taxes

//calcul la taxe spécifique pour un bateau à moteur
Taxe calculBateauTaxeSpecifique(const Bateau* bateau);

//calcul la taxe pour les bateaux à moteur et à voile
Taxe calculBateauTaxe(const Bateau* bateau);

#endif
