#include "Body.h"
#include<vector>

const char Body::body = 223;

Body::Body(COORD start) : x(start.X), y(start.Y) { }

Body::~Body(){ }

COORD Body::getCOORD() {
	COORD temp{ x,y };
	return temp;
}

void Body::Up(COORD size) {
	y = y - 1;
	BorderControl(size);
	system("CLS");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), getCOORD());
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << body;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void Body::Down(COORD size) {
	y = y + 1;
	BorderControl(size);
	system("CLS");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), getCOORD());

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << body;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void Body::Left(COORD size) {
	x = x - 1;
	BorderControl(size);
	system("CLS");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), getCOORD());

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << body;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void Body::Right(COORD size) {
	x = x + 1;
	BorderControl(size);
	system("CLS");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), getCOORD());

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << body;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

char Body::getBody(){return body;}

void Body::ChangeCoordinates(Body previous) {
	this->x = previous.x;
	this->y = previous.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), getCOORD());

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << body;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void Body::BorderControl(COORD size){
	if (x > size.X) x = 2;
	if (x < 1) x = size.X - 1;
	if (y < 1) y = size.Y - 1;
	if (y > size.Y) y = 2;
}