#include "Dependencies.h"

const int CountOfSym = 109;

int charPos = (CountOfSym / 2 - 5);							//start initializer of position of character
int prevPos;
int positionEntity;
int previousPositionEnemy;
int score;

char GameCharacter = '@';
char Enemy = '&';

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


void drawField() {

	for (int i = 0; i < CountOfSym; i++) {
		std::cout << arrGameField[i];
	}

}

void inputHandler() {

	char action;

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



}

// proccedures for create a enemy entities
bool EnemyEntityGotDie() {
	short counter = 0;

	for (int i = 0; i < CountOfSym; i++) {

		if (arrGameField[i] == '&') {
			counter = counter + 1;
		}
	}

	if (counter > 0) {
		return false;
	}
	else {
		return true;
	}
}

void spawnEntity() {
	srand(time(0));

	int arrPosJ[50];

	positionEntity = 11 + rand() % 97;

	arrGameField[positionEntity] = Enemy;

}
//

void getScorePlus() {

	if (charPos == positionEntity) {
		score = score + 1;
	}
	else {
		score = score;
	}
}

void getScoreOnScreen() {

	std::cout << std::endl << "score = " << score << std::endl;

}

int main() {

	bool gameAlreadyRunning = true;

	while (gameAlreadyRunning) {


		arrGameField[charPos] = GameCharacter;

		getNConstants(arrGameField);
		drawField();
		getScorePlus();
		getScoreOnScreen();

		if (EnemyEntityGotDie()) {
			spawnEntity();
		}

		prevPos = charPos;

		inputHandler();
		

		getCls();
	}

	return 0;
}