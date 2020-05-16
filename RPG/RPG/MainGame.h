#pragma once
#pragma once
#ifndef MAINGAME_H
#define MAINGAME_H
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include "Player.h"

Player* Players[10];
typedef struct Map {
	char** palya;
	int szel, hossz;
}Map;

void DrawMainBar();
void CreatePlayers(Map* map,int x,int y);
void DisplayPlayers();
Map* ReadMap(const char* filename);
void WriteMap(Map* map);

#endif //!MAINGAME_H