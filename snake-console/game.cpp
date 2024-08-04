#include "Dependencies.h"

const int CountOfSym = 109;

int charPos = (CountOfSym / 2 - 5);							//start initializer of position of character
int prevPos;

const std::string arrMessages[10] = { "invalid input", "", "", "", "", "", "", "", "", ""}; //array of messages for unexpected situations

char arrGameField[CountOfSym] =								// main array of gamefield symbols
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

		for (int i = 0; i < 109; i++) {					// Loop for draw a gamefield
			std::cout << arrGameField[i];
		}

		prevPos = charPos;

		std::cin >> action;
		

		if (action == 'w') {							// handler for check action for input chars
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
			std::cout << arrMessages[0];
		}												
		arrGameField[prevPos] = ' ';


		Sleep(200);
		system("cls");
	}

	return 0;
}