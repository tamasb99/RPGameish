#include "Player.h"

Player* Const(class c) {
	Player* P = (Player*)calloc(1, sizeof(Player));
	if (!P) { printf("sikertelen jatekosletrehozas"); }
	P->spec_abilityname = (char*)calloc(30, sizeof(char));
	if (!P->spec_abilityname) { printf("sikertelen jatekosletrehozas"); }
	P->name = (char*)calloc(30, sizeof(char));
	if (!P->name) { printf("sikertelen jatekosletrehozas"); }

	switch (c)
	{
	case EXINOS:
		P->health = 100;
		P->spec_abilityname = "fireball"; //ilyen kullonleges tamadas kepessegek
		P->spec_ab_attack = 12;
		P->normattack = 4;
		P->name = "Exinos";
		P->defense = 6;
		P->CharacterP = c;
	case DONLONG:
		P->health = 100;
		P->spec_abilityname = "icebreath";
		P->spec_ab_attack = 10;
		P->normattack = 3;
		P->name = "Donglong";
		P->defense = 5;
		P->CharacterP = c;
	case CSINGCSONG:
		P->health = 100;
		P->spec_abilityname = "acidspit";
		P->spec_ab_attack = 14;
		P->normattack = 5;
		P->name = "Csingcsong";
		P->defense = 4;
		P->CharacterP = c;
	default:
		P->health = 10;
		P->spec_abilityname = "none";
		P->spec_ab_attack = 0;
		P->normattack = 0;
		P->name = "noob";
		P->defense = 0;
		break;
	}
	return P;
}

void DisplayStatsLeft(Player* P) {
	printf("\t%s %i\n\t%s\n\n", P->name, P->health, P->spec_abilityname, P->spec_abilityname);
}

void DisplayStatsRightUp(Player* P) {
	//Console.SetCursorPosition(40, 40);
	printf("\t%s %i\n\t%s", P->name, P->health, P->spec_abilityname, P->spec_abilityname);
	//itt leragadtam nem tudom C-ben hogy mozgassam a kurzort szepen
}