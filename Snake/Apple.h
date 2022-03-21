#pragma once
#include<iostream>
#include<conio.h>
#include <windows.h>
using namespace std;
class Apple
{
	int x = 0, y = 0;
	static const char body;

public:

	Apple() {};
	Apple(COORD coord);
	~Apple();
	COORD getCOORD();
	void setX(int x);
	void setY(int y);
	char getBody();
};

