
#pragma once
#ifndef MAINGAME_H
#define MAINGAME_H
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include "Player.h"
#include <time.h>

Player* Players[10];
typedef struct Map {
	char** palya;
	int szel, hossz;
}Map;
//static int Px = 8;
//static int Py = 4;
 static int maxbonus1 = 10;
 static int maxbonus = 20;
 static int maxbonus3 = 30;
 static int coins = 0;
 static int level = 1;
 static int over = 0;
 static int maxenemy = 5;
 static int highscore = 0;
 //static int end = 0;
void DrawMainBar();
void CreatePlayers(Map* map,int x,int y);
int  Movement(char option, Map* map);
void DisplayPlayers();
Map* ReadMap(const char* filename);
void WriteMap(Map* map);
void SetScreenColour();
void SetRandomBonusCoins(Map* map,int maxbonus);
void PrintMainMenu();
Map* SetLevel(const char filename);
void SetRandomEnemy(Map* m);
void DeleteEnemy(Map* m);

#endif //!MAINGAME_H