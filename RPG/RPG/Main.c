//#include "Player.h"
#include <stdio.h>
#include <stdlib.h>
#include "MainGame.h"
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN


int main() {

	char c;
	printf("\t\t\tDo you wanna start the game?\n\t\t\t\tPress enter for it!\n");
	scanf_s("%c", &c);
	if (c == '\n') {
		DrawMainBar();
	}
	else { printf("Why don't you wanna play the game?:("); }
	Map* m=	ReadMap("map2.txt");
	CreatePlayers(m, 8, 4);
	WriteMap(m);
	return 0;
}