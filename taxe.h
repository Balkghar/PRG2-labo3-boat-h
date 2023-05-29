#ifndef TAXE_H
#define TAXE_H
#include "bateau.h"
#include "inttypes.h"
//Constantes sur les taxes annuelles en euros
const char* const MONNAIE = "Euros";

const uint8_t TAXE_BASE_VOILIER = 50;
const uint8_t TAXE_BASE_MOTEUR = 100;

const uint8_t VOILIER_LIMITE_TAILLE_VOILE = 200;//200m^2
const uint8_t TAXE_VOILIER_PETITE_VOILE = 0;
const uint8_t TAXE_VOILIER_GRANDE_VOILE = 25;

const uint8_t PECHE_LIMITE_TONNAGE = 20;//20 tonnes
const uint8_t TAXE_PECHE_PETIT_TONNAGE = 0;
const uint8_t TAXE_PECHE_GRAND_TONNAGE = 100;

const uint8_t PLAISANCE_LIMITE_MOTEUR = 100;//100 CV
const uint8_t TAXE_PLAISANCE_PETIT_MOTEUR = 50;
const uint8_t TAXE_PLAISANCE_GRAND_MOTEUR_FACTEUR = 15;//15 par mètre de la longueur

// fonction de calcul des taxes

#endif
