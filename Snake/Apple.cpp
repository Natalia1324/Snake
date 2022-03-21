#include "Apple.h"

const char Apple::body = '0';

Apple::Apple(COORD coord): x(coord.X), y(coord.Y) {}

Apple::~Apple(){}

COORD Apple::getCOORD(){
	COORD temp{ x,y };
	return temp;
}

void Apple::setX(int x) {
	this->x = x;
}

void Apple::setY(int y) {
	this->y = y;
}

char Apple::getBody() {
	return body;
}