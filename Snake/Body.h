#pragma once
#include<iostream>
#include<conio.h>
#include <windows.h>
using namespace std;

class Body
{
protected:

	int x, y;
	
public:
	static const char body;


	Body();
	Body(COORD start);
	~Body();
	COORD getCOORD();
	char getBody();
	void Up(COORD size);
	void Down(COORD size);
	void Left(COORD size);
	void Right(COORD size);
	void ChangeCoordinates(Body previous);
	void BorderControl(COORD size);
};

