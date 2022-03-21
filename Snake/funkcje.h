#pragma once
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<cstdio>
#include<stdlib.h>
#include"Body.h"
#include<vector>
#include<random>
#include"Apple.h"

using namespace std;

static COORD rozmiar{ 40,20 };
static COORD half_size{ rozmiar.X / 2, rozmiar.Y / 2 };

void drawBoard(COORD size);

void changePositions(vector<Body>& cialo, COORD poprzednie);

bool checkApple(Apple jabko, vector<Body>& cialo, Body glowa);

Apple randomAppleGenerator(vector<Body> cialo, Body glowa);

vector<Apple> AppleVectorGenerator(vector<Body> cialo, Body glowa, int size);

void printApple(vector<Apple> jabka);

void checkColisionWithApple(vector<Apple>& jabka, Body glowa, vector<Body>& cialo);

void game_over();

void checkColisionWithItself(Body glowa, vector<Body>& cialo);

void terminal(vector<Apple>& randomApple, Body glowa, vector<Body>& cialo, COORD poprzednie);

void startConditions(Body glowa);

void title();

void startOptions(int& option);

void startScreen();

void game();