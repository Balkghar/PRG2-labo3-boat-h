#ifndef BATEAU_H
#define BATEAU_H
#include "inttypes.h"

typedef enum { MOTEUR, VOILIER } BateauType;
typedef enum { PECHE, PLAISANCE } BateauMoteurType;

struct Bateau {
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
				struct {
					uint8_t tonnesPoissonMax;
				} peche;
				struct {
					uint8_t longueur;
					const char* proprietaire;
				} plaisance;
			} details;
		} motorise;
	} details;
};

typedef struct {
	const char* name;
} Bateau;

// TODO: compléter la struct Bateau

#endif
