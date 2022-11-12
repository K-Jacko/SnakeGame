//
// Created by Wake on 05/11/2022.
//

#ifndef SNAKEGAME_GAME_H
#define SNAKEGAME_GAME_H

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

#define MAX 60


extern short sDirection;
//extern bool gameOver;

void initGrid(int x, int y);
void unit(int x, int y);
void drawGrid();
void drawFood();
void drawSnake();
void random(int&,int&);

#endif //SNAKEGAME_GAME_H
