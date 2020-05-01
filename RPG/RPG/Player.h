#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdlib.h>
#include <stdio.h>

typedef struct Player {
	int health;
	char* name;
	char* spec_abilityname;
	int spec_ab_attack;
	int normattack;
	int defense;
	class CharacterP;
}Player;

typedef enum PlayableChar {
	EXINOS,
	DONLONG,
	CSINGCSONG,
}class;

Player* Const(class C);
	


#endif // !EXINOS_H
