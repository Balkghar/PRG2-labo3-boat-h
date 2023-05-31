/*
  ---------------------------------------------------------------------------
  Nom du fichier : statistique.h
  Auteur(s)      : Samuel Roland, Hugo Germano, Patrick Maillard
  Date creation  : 30.05.2023
  
  Description    : Ce fichier contient les déclarations des fonctions
  permettant le calcul de statistique

  Remarque(s)    : -

  Compilateur : gcc 12.3.1
  ---------------------------------------------------------------------------
*/

#ifndef STATISTIQUE_H
#define STATISTIQUE_H
#include <stdio.h>

//compare deux doubles
int comparerDouble(const void* a, const void* b);

//Calcul de la médiane d'un tableau de double
double mediane(const double* tableau, size_t taille);

//Calcul de la somme d'un tableau de double
double somme(const double* tableau, size_t taille);

//Calcul de la moyenne d'un tableau de double
double moyenne(const double* tableau, size_t taille);

//Calcul de l'écart type d'un tableau de double
double ecartType(const double* tableau, size_t taille);

#endif
