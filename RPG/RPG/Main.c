#include <stdio.h>
#include <stdlib.h>
#include "MainGame.h"
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN


int main() {
	bool finished = false;
	SetScreenColour();
	char c;
	printf("\t\t\tDo you wanna start the game?\n\t\t\t\tPress enter for it!\n");
	scanf_s("%c", &c);
	Map* m;
	DrawMainBar();
	if (c == '\n') {
		PrintMainMenu();
		while (!finished) {
			// printf("\t\t\t");
			
			//char option2 = _getch();
			//	if (option2 == ) {
			if (level == 1) {
				 m = ReadMap("map.txt");
				CreatePlayers(m, Px, Py);
				SetRandomBonusCoins(m, maxbonus1);
				while (1) {
					WriteMap(m);
					DisplayPlayers();
					char option = _getch();
					if (option == 27) { break; }
					if (Movement(option, m)==1) {break; }
					if (Movement(option, m) == 2) { exit(1); }
					system("CLS");
				}
		 	level++;
				
			}
			if (level == 2) {
				Map* m2 = ReadMap("map2.txt");
				CreatePlayers(m2, Px, Py);
				SetRandomBonusCoins(m2, maxbonus);
				while (1) {
					WriteMap(m2);
					DisplayPlayers();
					char option2 = _getch();
					if (option2 == 27) { break; }
					if (Movement(option2, m2) == 1) { break; }
					if (Movement(option2, m2) == 2) { exit(1); }
					system("CLS");

				}
				level++;
			}
				if (level == 3) {
					Map* m3 = ReadMap("map3.txt");
					CreatePlayers(m3, Px, Py);
					SetRandomBonusCoins(m3, maxbonus);
					while (1) {
						WriteMap(m3);
						DisplayPlayers();
						char option3 = _getch();
						if (option3 == 27) { break; }
						if (Movement(option3, m3) == 1) { break; }
						if (Movement(option3, m3) == 2) { exit(1); }
						system("CLS");
				    }
					if (level == 3) finished = true;
		     	}
		

		}
	}
}

	//else { printf("Why don't you wanna play the game?:("); }
	//return 0;
