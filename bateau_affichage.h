/*
  ---------------------------------------------------------------------------
  Nom du fichier : bateau_affichage.h
  Auteur(s)      : Samuel Roland, Hugo Germano, Patrick Maillard
  Date creation  : 30.05.2023
  
  Description    : Ce fichier contient la déclaration de la fonction permettant
  d'afficher les détails d'un bateau

  Remarque(s)    : -

  Compilateur : gcc 12.3.1
  ---------------------------------------------------------------------------
*/


#ifndef BATEAU_AFFICHAGE_H
#define BATEAU_AFFICHAGE_H
#include "bateau.h"
#include "port.h"

void afficherBateau(const TaxeCalculee* bateau);

#endif
