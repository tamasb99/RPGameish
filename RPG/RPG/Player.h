#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdlib.h>
#include <stdio.h>


typedef enum PlayableChar {
	EXINOS,
	DONLONG,
	CSINGCSONG,
}PlayableChar;

static int Px=8;
static int Py=4;

typedef struct Player {
	int health;
	char* name;
	char* spec_abilityname;
	int spec_ab_attack;
	int normattack;
	int defense;
	PlayableChar CharacterP;
}Player;


Player* Const(PlayableChar C);
void DisplayStatsLeft(Player* P);



#endif // !EXINOS_H
