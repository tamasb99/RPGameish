#include "MainGame.h"
#include "Player.h"
#include <Windows.h>




void DrawMainBar() {
	FILE* fin = fopen("Gametitle.txt", "r");
	//char** text = (char**)calloc(30, sizeof(char*));
	//for (int i = 0; i < 30; ++i) {
	//	text[i] = (char*)calloc(72, sizeof(char));
	//}
	char text[80];

	for (int i = 0; i < 30; ++i) {
		fgets(text, 80, fin);
		//fscanf(fin, "\n");
		printf("\t\t\t%s\n", text);
	}
	fclose(fin);

}

void DisplayPlayers() {
	for (int i = 0; i < 10; ++i) {
		DisplayStatsLeft(Players[i]);
		printf("\n");
	}
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
			else if (map->palya[i][j] == '3' && (j == 0 || j == map->szel - 1)) {
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

		}
		printf("\n");
	}
}
void CreatePlayers(Map* map, int x, int y) {
	map->palya[x][y] = 'x';
}


