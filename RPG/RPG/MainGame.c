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
	printf("HIGH SCORE: %i \t\tYOUR SCORE: %i", highscore, coins);
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
				printf("_");
			}
			else if (map->palya[i][j] == '3' && (j == 0 || j == map->szel-1)) {
				printf("|");
			}
			if (map->palya[i][j] == '1') {
				printf("#");
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
			if (map->palya[i][j] == 'e') {
				printf(">");
			}

		}
		printf("\n");
	}
}
void SetScreenColour(){ //szin bealitas
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsole
	SetConsoleTextAttribute(hStdOut, (BACKGROUND_RED| FOREGROUND_BLUE));
}
void SetRandomBonusCoins(Map* map,int maxbonus){  //bonospontok generalasa
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
void SetRandomEnemy(Map* map){ //random poz-ra enemy-ket spawnol (kicsit nehez emiatt a jatek de eleg erdekesnek teszi igy
	int i = 0;
	srand(time(NULL));
	while (i < maxenemy) {
		int randy = (int)(rand() % (map->szel - 1)) + 1;
		int randx = (int)(rand() % (map->hossz - 1)) + 1;
		if (map->palya[randx][randy] == '0') {
			++i;
			map->palya[randx][randy] = 'e';
			

		}
	}
}
void DeleteEnemy(Map* m) {
	for (int i = 0; i < m->hossz; ++i) {
		for (int j = 0; j < m->szel; ++j) {
			if (m->palya[i][j] == 'e') {
				m->palya[i][j] = '0';
			}
		}
	}
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
	if (option == 's'||option=='S') {
		Px += 1; 
	}
	if (option == 'a' || option == 'A') {
		Py -= 1; 
	}
	if (option == 'w' || option == 'W') {
		Px--;
	}
	if (option == 'd' || option == 'D') {
		Py += 1; 
	}
	if (map->palya[Px][Py] == '0') {
		map->palya[Px][Py] = 'x';
		map->palya[elozoX][elozoY] = '0';
	}
	if (map->palya[Px][Py] == '1' || map->palya[Px][Py] == '3' || map->palya[Px][Py]=='e') { // ha falba megy vagy enemybe
		system("CLS");
		FILE* fin = fopen("highscore.txt", "r");
		fscanf(fin, "%i", &highscore);
		fclose(fin);
		FILE* fout = fopen("highscore.txt", "w");
		fprintf(fout, "%i", coins);
		fclose(fout);
		printf("Game over!!!\nYou lost.\n");
		printf("HIGH SCORE: %i YOUR SCORE: %i", highscore,coins);
		veg=2;
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


