#include "Dependencies.h"

const int CountOfSym = 109;

int charPos = (CountOfSym / 2 - 5);							//start initializer of position of character
int prevPos;
int positionEnemy;
int previousPositionEnemy;

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
char Enemy = '&';


void drawField() {

	for (int i = 0; i < CountOfSym; i++) {
		std::cout << arrGameField[i];
	}

}

// proccedures for create a enemy entities
bool EnemyEntityGotDie() {
	if (arrGameField[positionEnemy] == '&') {
		return false;
	}
	else {
		return true;
	}
}

void spawnEntity() {
	srand(time(0));

	int positionEntity = 11 + rand() % 97;

	arrGameField[positionEntity] = Enemy;

	positionEnemy = positionEntity;
	previousPositionEnemy = positionEntity;

}
//

void getNConstants() {
	arrGameField[10] = '\n';
	arrGameField[21] = '\n';
	arrGameField[32] = '\n';
	arrGameField[43] = '\n';
	arrGameField[54] = '\n';
	arrGameField[65] = '\n';
	arrGameField[76] = '\n';
	arrGameField[87] = '\n';
	arrGameField[98] = '\n';

}

void getCls() {
	Sleep(200);
	system("cls");
}


int main() {

	while (true) {


		char action;
		arrGameField[charPos] = GameCharacter;

		getNConstants();
		drawField();
		if (EnemyEntityGotDie) {
			spawnEntity();
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


		getCls();
	}

	return 0;
}