#ifndef BATEAU_H
#define BATEAU_H
#include "inttypes.h"

typedef enum { MOTEUR, VOILIER } BateauType;
static const char* const BATEAU_TYPES[] = {"moteur", "voile"};
typedef enum { PECHE, PLAISANCE } BateauMoteurType;
static const char* const BATEAU_CATEGORIES[] = {"peche", "plaisance"};

typedef struct Bateau {
	const char* nom;
	BateauType type;
	union {
		//Pour les bateaux de type VOILIER
		struct {
			uint16_t surfaceVoilure;
		} voilier;

		//Pour les bateaux de type MOTEUR
		struct {
			uint16_t puissanceMoteurs;
			BateauMoteurType sousCategorie;
			union {
				//Pour les sousCategorie PECHE
				struct {
					uint8_t tonnageMax;
				} peche;

				//Pour les sousCategorie PLAISANCE
				struct {
					uint8_t longueur;
					const char* proprietaire;
				} plaisance;
			} details;
		} motorise;
	} details;
} Bateau;


#endif
