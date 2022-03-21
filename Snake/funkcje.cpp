#include"funkcje.h"


void drawBoard(COORD size) {
	for (int i = 0; i <= size.X; i++) {
		COORD temp{ i,0 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), temp);
		cout << '_';
	}

	for (int i = 0; i <= size.X; i++) {
		COORD temp{ i,size.Y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), temp);
		cout << '_';
	}

	for (int i = 1; i <= size.Y; i++) {
		COORD temp{ 0, i };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), temp);
		cout << '|';
	}

	for (int i = 1; i <= size.Y; i++) {
		COORD temp{ size.X, i };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), temp);
		cout << '|';
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, size.Y });
	cout << "\n\n\n\n\n Press x to exit...";

}
void changePositions(vector<Body>& cialo, COORD poprzednie) {
	COORD temporary;
	if (!cialo.empty()) {
		temporary = cialo[0].getCOORD();
		cialo[0].ChangeCoordinates(poprzednie);
		for (int i = 1; i < cialo.size(); i++) {
			COORD ups = cialo[i].getCOORD();
			cialo[i].ChangeCoordinates(temporary);
			cialo[i].BorderControl(rozmiar);
			temporary = ups;
		}
	}
}
bool checkApple(vector<Apple> jabka, Apple jabko, vector<Body>& cialo, Body glowa) {

	if (jabko.getCOORD().Y == glowa.getCOORD().Y && jabko.getCOORD().X == glowa.getCOORD().X) return false;
	else for (int i = 0; i < cialo.size(); i++) {
		if (jabko.getCOORD().Y == cialo[i].getCOORD().Y && jabko.getCOORD().X == cialo[i].getCOORD().X) return false;
	}
	if (!jabka.empty()) {
		for (auto j : jabka) {
			if (jabko.getCOORD().Y == j.getCOORD().Y && jabko.getCOORD().X == j.getCOORD().X) return false;
		}
	}

	return true;
}
Apple randomAppleGenerator(vector<Apple>& jabka, vector<Body> cialo, Body glowa) {
	Apple jabko;
	do {
		random_device dev1;
		mt19937 rng1(dev1());
		uniform_int_distribution<mt19937::result_type> dist1(1, rozmiar.X - 1);
		jabko.setX(dist1(rng1));

		random_device dev2;
		mt19937 rng2(dev2());
		uniform_int_distribution<mt19937::result_type> dist2(1, rozmiar.Y - 1);
		jabko.setY(dist2(rng2));
	} while (!checkApple(jabka ,jabko, cialo, glowa));
	return jabko;
}
vector<Apple> AppleVectorGenerator(vector<Body> cialo, Body glowa, int size) {
	vector<Apple> jabka;
	for (int i = 0; i < size; i++) {
		Apple temp;
		temp = randomAppleGenerator(jabka, cialo, glowa);
		jabka.push_back(temp);
	}
	return jabka;
}
void printApple(vector<Apple> jabka) {

	for (int i = 0; i < jabka.size(); i++) {

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), jabka[i].getCOORD());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << jabka[i].getBody();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
}
void checkColisionWithApple(vector<Apple>& jabka, Body glowa, vector<Body>& cialo) {
	for (int i = 0; i < jabka.size(); i++) {
		if ((jabka[i].getCOORD().Y == glowa.getCOORD().Y && jabka[i].getCOORD().X == glowa.getCOORD().X)) {
			Body element(glowa.getCOORD());
			cialo.push_back(element);
			if (cialo.size() + 1 + jabka.size() >= (rozmiar.X - 1) * (rozmiar.Y - 1)) {}
			else jabka[i] = randomAppleGenerator(jabka, cialo, glowa);
		}
	}
}
void game_over() {
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "\n\n\n\n\n\n\n";
	cout << " __   __  _______  __   __    ___      _______  _______  _______ " << endl;
	cout << "|  | |  ||       ||  | |  |  |   |    |       ||       ||       |" << endl;
	cout << "|  |_|  ||   _   ||  | |  |  |   |    |   _   ||  _____||_     _|" << endl;
	cout << "|       ||  | |  ||  |_|  |  |   |    |  | |  || |_____   |   |  " << endl;
	cout << "|_     _||  |_|  ||       |  |   |___ |  |_|  ||_____  |  |   |  " << endl;
	cout << "  |   |  |       ||       |  |       ||       | _____| |  |   |  " << endl;
	cout << "  |___|  |_______||_______|  |_______||_______||_______|  |___|  " << endl;
	cout << "\n\n\n\n\n\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	exit(0);
}
void checkColisionWithItself(Body glowa, vector<Body>& cialo) {
	if (cialo.size() > 3) {
		for (int i = 0; i < cialo.size(); i++) {
			if (cialo[i].getCOORD().Y == glowa.getCOORD().Y && cialo[i].getCOORD().X == glowa.getCOORD().X) game_over();
		}
	}
}
void terminal(vector<Apple>& randomApple, Body glowa, vector<Body>& cialo, COORD poprzednie) {
	checkColisionWithApple(randomApple, glowa, cialo);
	printApple(randomApple);
	changePositions(cialo, poprzednie);
	checkColisionWithItself(glowa, cialo);
	drawBoard(rozmiar);
}
void startConditions(Body glowa) {
	drawBoard(rozmiar);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), half_size);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << glowa.getBody();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
void title() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "	 _______  __    _  _______  ___   _  _______ " << endl;
	cout << "	|       ||  |  | ||   _   ||   | | ||       |" << endl;
	cout << "	|  _____||   |_| ||  |_|  ||   |_| ||    ___|" << endl;
	cout << "	| |_____ |       ||       ||      _||   |___ " << endl;
	cout << "	|_____  ||  _    ||       ||     |_ |    ___|" << endl;
	cout << "	 _____| || | |   ||   _   ||    _  ||   |___ " << endl;
	cout << "	|_______||_|  |__||__| |__||___| |_||_______|" << endl;
	cout << "\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
void startOptions(int& option) {
	if (option > 2) option = option - 2;
	if (option < 1) option = option + 2;



	if (option == 1) {
		cout << "		      " << ">> Start Game <<" << endl;
		cout << "		      " << "   Exit Game" << endl;
	}
	else if (option == 2) {

		cout << "		      " << "   Start Game" << endl;
		cout << "		      " << ">> Exit Game <<" << endl;
	}

}
void startScreen() {

	int option = 1;
	title();
	startOptions(option);
	bool condition = true;


	while (condition) {
		if (_kbhit) {
			switch (_getch()) {
			case 'w':
				--option;
				system("CLS");
				title();
				startOptions(option);
				break;
			case 's':
				++option;
				system("CLS");
				title();
				startOptions(option);
				break;
			case' ':
				if (option == 1) condition = false;
				if (option == 2) exit(0);
				break;
			default:
				break;
			}
		}
	}
	system("CLS");
}
void game() {

	bool game_over = false;
	vector<Body> cialo;
	Body glowa(half_size);
	int ilosc_jablek = 20;
	startConditions(glowa);
	vector<Apple> randomApple = AppleVectorGenerator(cialo, glowa, ilosc_jablek);

	while (!game_over) {
		if (_kbhit) {
			COORD poprzednie = glowa.getCOORD();
			switch (_getch()) {
			case 'w':
				glowa.Up(rozmiar);
				break;
			case 'a':
				glowa.Left(rozmiar);
				break;
			case 's':
				glowa.Down(rozmiar);
				break;
			case 'd':
				glowa.Right(rozmiar);
				break;
			case 'x':
				game_over = true;
				break;
			default:
				break;
			}
			terminal(randomApple, glowa, cialo, poprzednie);
		}
	}
}