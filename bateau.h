/*
  ---------------------------------------------------------------------------
  Nom du fichier : bateau.h
  Auteur(s)      : Samuel Roland, Hugo Germano, Patrick Maillard
  Date creation  : 30.05.2023

  Description    : Ce fichier contient la structure des différents types de
  bateaux du port.

  Remarque(s)    : -
  
  Compilateur    : gcc 12.3.1
  ---------------------------------------------------------------------------
*/

#ifndef BATEAU_H
#define BATEAU_H
#include "inttypes.h"
#define PUISSANCE_MOTEURS_UNITE "CV"
#define LONGUEUR_BATEAU_UNITE "m"
#define TONNAGE_PECHE_UNITE "t"
#define SURFACE_VOILURE_UNITE "m^2"

typedef enum { MOTEUR, VOILIER } BateauType;
static const char* const BATEAU_TYPES[] = {"moteur", "voile"};
typedef enum { PECHE, PLAISANCE } BateauMoteurType;
static const char* const BATEAU_CATEGORIES[] = {"peche", "plaisance"};

//Détails sur les bateaux de type VOILIER
typedef struct {
	uint16_t surfaceVoilure;//en mètre carré
} VoilierDetails;

//Détails liés aux bateaux de PECHE à moteur
typedef struct {
	uint8_t tonnageMax;//en tonnes
} BateauPecheDetails;

//Détails liés aux bateaux de PLAISANCE à moteur
typedef struct {
	uint8_t longueur;//en mètre
	const char* proprietaire;
} BateauPlaisanceDetails;

//Détails liés aux types de bateaux à moteur (BateauMoteurType)
typedef union {
	BateauPecheDetails peche;
	BateauPlaisanceDetails plaisance;
} BateauMoteurTypeUnion;

//Détails sur les bateaux de type MOTEUR
typedef struct {
	uint16_t puissanceMoteurs;//en Cheval-Vapeur
	BateauMoteurType sousCategorie;
	BateauMoteurTypeUnion details;
} MotoriseDetails;

//Détails liés aux types de bateaux (BateauType)
typedef union {
	VoilierDetails voilier;
	MotoriseDetails motorise;
} BateauTypeUnion;

typedef struct Bateau {
	const char* nom;
	BateauType type;
	BateauTypeUnion details;
} Bateau;

#endif
