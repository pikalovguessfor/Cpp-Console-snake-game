#include "Dependencies.h"

const int CountOfSym = 109;

int charPos = (CountOfSym / 2 - 5);
int prevPos;


char arrGameField[CountOfSym] =
{
	'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '\n',
	'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '\n',
	'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '\n',
	'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '\n',
	'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '\n',
	'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '\n',
	'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '\n',
	'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '\n',
	'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '\n',
	'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 
};
char GameCharacter = '@';

int main() {

	while (true) {
		char action;

		arrGameField[charPos] = GameCharacter;

		for (int i = 0; i < 109; i++) { // Loop for draw a gamefield
			std::cout << arrGameField[i];
		}

		prevPos = charPos;

		std::cin >> action;
		

		if (action == 'w') {
			charPos = charPos - 11;
			
		}
		else if (action == 's') {
			charPos = charPos + 11;
		}
		else if (action == 'a') {
			charPos = charPos - 1;
		}
		else if (action == 'd') {
			charPos = charPos + 1;
		}
		else {

		}
		arrGameField[prevPos] = ' ';


		Sleep(200);
		system("cls");
	}

	return 0;
}