#include "MainGame.h"
#include "Player.h"
#include <Windows.h>
#include <time.h>



void DrawMainBar() {
	FILE* fin = fopen("Gametitle.txt", "r");
		char text[80];

	for (int i = 0; i < 30; ++i) {
		fgets(text, 80, fin);
		//fscanf(fin, "\n");
		printf("\t\t\t%s\n", text);
	}
	fclose(fin);

}

void DisplayPlayers() {
	//for (int i = 0; i < 10; ++i) {
		//DisplayStatsLeft(Players[i]);
		printf("%i ",coins);
}
Map* ReadMap(const char* filename){
	FILE* fin = fopen(filename, "rt");
	if (!fin) { printf("sikertelen palyabeolv"); exit(1); }
	Map* map = (Map*)calloc(1, sizeof(Map));
	fscanf(fin, "%i%i\n", &map->hossz, &map->szel);
	map->palya = (char**)calloc(map->hossz, sizeof(char*));
	for (int i = 0; i < map->hossz; ++i) {
		map->palya[i] = (char*)calloc(map->szel, sizeof(char));
	}
	for (int i = 0; i < map->hossz; ++i) {
		for (int j = 0; j < map->szel; ++j) {
			fscanf(fin, "%c", & map->palya[i][j]);
		}
		fscanf(fin, "\n");
	}
	fclose(fin);
	return map;
}
void WriteMap(Map* map){
	
	for (int i = 0; i < map->hossz; ++i) {
		for (int j = 0; j < map->szel; ++j) {
			if (map->palya[i][j] == '3' && (i == 0 || i == map->hossz - 1)) {
				printf("-");
			}
			else if (map->palya[i][j] == '3' && (j == 0 || j == map->szel-1)) {
				printf("|");
			}
			if (map->palya[i][j] == '1') {
				printf("*");
			}
			if (map->palya[i][j] == '0') {
				printf(" ");
			}
			if (map->palya[i][j] == 'x') {
				printf("X");

			}
			if (map->palya[i][j] == '2') {
				printf("@");
			}
			if (map->palya[i][j] == 'C') {
				printf("$");
			}

		}
		printf("\n");
	}
}
void SetScreenColour(){
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsole
	SetConsoleTextAttribute(hStdOut, (BACKGROUND_GREEN));
}
void SetRandomBonusCoins(Map* map,int maxbonus){
	int i = 0;
	srand(time(NULL));
	while (i < maxbonus) {
		int randy = (int)(rand() % (map->szel-1))+ 1;
		int randx= (int)(rand() %(map->hossz-1)) +1;
		if (map->palya[randx][randy] == '0') {
			++i;
			map->palya[randx][randy] = 'C';
			//printf("x=%i ", randx);
			//printf("y=%i\n", randy);

		}
	}
}
void PrintMainMenu(){
    //gotoxy(30, 40);
	printf("\t\t\t\t\t 1. START GAME\n");
	printf("\t\t\t\t\t _____________\n");
	printf("\t\t\t\t\t  2. OPTIONS\n");
	printf("\t\t\t\t\t _____________\n");
	printf("\t\t\t\t\t EXIT .Escape\n");

}
/*Map* SetLevel(const char* filename)
{
	Map* m = ReadMap(filename);
	CreatePlayers(m, Px, Py);
	SetRandomBonusCoins(m,maxbonus);
	return m;
}*/

void CreatePlayers(Map* map, int x, int y) {
	map->palya[x][y] = 'x';
}

int Movement(char option, Map* map) {
	int veg = 0;
	int elozoX = Px;
	int elozoY = Py;
	if (option == 's') {
		Px += 1;
	}
	if (option == 'a') {
		Py -= 1;
	}
	if (option == 'w') {
		Px -= 1;
	}
	if (option == 'd') {
		Py += 1;
	}
	if (map->palya[Px][Py] == '0') {
		map->palya[Px][Py] = 'x';
		map->palya[elozoX][elozoY] = '0';
	}
	if (map->palya[Px][Py] == '1' || map->palya[Px][Py] == '3') {
		system("CLS");
		printf("Game over!!!\nYou lost."); 
		printf("Your score was: %i", coins);
		//exit(1);
	}
	if (map->palya[Px][Py] == 'C') {
		map->palya[Px][Py] = 'x';
		map->palya[elozoX][elozoY] = '0';
		coins++;
	}
	if (map->palya[Px][Py] == '2') {
		//system("CLS");
		veg = 1;
		printf("Congratulations you passed the level:)");	
		}
	return veg;
}


