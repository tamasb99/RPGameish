#include "Game.h"


void Game() {
	bool finished = false;
	SetScreenColour();
	char c;
	printf("\t\t\tDo you wanna start the game?\n\t\t\t\tPress enter for it!\n");
	scanf_s("%c", &c);
	Map* m;
	int next = 1;
	DrawMainBar();
	if (c == '\n') {
		PrintMainMenu();
		char menu = _getch();
		if (menu == '1') {


			while (!finished) {

				if (level == 1) {   // elso szint
					m = ReadMap("map.txt");
					CreatePlayers(m, Px, Py);
					SetRandomBonusCoins(m, maxbonus1);
					while (1) {
						DeleteEnemy(m);
						SetRandomEnemy(m);
						WriteMap(m);
						DisplayPlayers();
						char option = _getch();
						if (option == 27) { break; }
						if (Movement(option, m) == 1) { maxenemy += 5; next++; break; }
						if (Movement(option, m) == 2) { exit(1); }
						system("CLS");
					}
					level = next;

				}
				if (level == 2) { //2.szint
					Map* m2 = ReadMap("map2.txt");
					CreatePlayers(m2, Px, Py);
					SetRandomBonusCoins(m2, maxbonus);
					while (1) {
						DeleteEnemy(m2);
						SetRandomEnemy(m2);
						WriteMap(m2);
						DisplayPlayers();
						char option2 = _getch();
						if (option2 == 27) { break; }
						if (Movement(option2, m2) == 1) { next++; maxenemy += 5; break; }
						if (Movement(option2, m2) == 2) { exit(1); }
						system("CLS");

					}
					level = next;
				}
				if (level == 3) { //3. szint
					Map* m3 = ReadMap("map3.txt");
					CreatePlayers(m3, Px, Py);
					SetRandomBonusCoins(m3, maxbonus);
					while (1) {
						WriteMap(m3);
						DisplayPlayers();
						char option3 = _getch();
						if (option3 == 27) { break; }
						if (Movement(option3, m3) == 1) {break; }
						if (Movement(option3, m3) == 2) { exit(1); }
						system("CLS");
					}
					if (level == 3) finished = true;
				}


			}
		}
		else if (menu == '2') {
			printf("Sorry nothing to look here\n");
		}
		else exit(1);
	}
	else { printf("Why don't you wanna play the game?:("); }
}