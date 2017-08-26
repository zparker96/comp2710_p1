/*
Zachary Parker
zbp0003@auburn.edu
Project1.cpp
Compiled using g++ compiler on University TUX machine. Only compile this .cpp file if the provided highscores.txt file is in the same directory.

I used references from www.stackoverflow.com and www.cplusplus.com to obtain various pieces of information, 
such as how to sort an array in ascending order, how to use parallel arrays, and how to utilize cin.ignore() when dealing with user input. 
I also used files posted on Canvas for clarification of syntax in order to complete this assignment.
*/

#include <fstream> 
#include <iostream> 
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <string.h>
#include <limits>
using namespace std;

const int ARRAY_MAX = 10;

class Character;
class Encounter;
class Highscore;
class Menu;

class Character {
public:
	Character();
	bool wonGame();
	bool alive();
	int changeTime(int difference);
	int changeMoney(int difference);
	int changeIntelligence(int difference);
	int decrementSteps();
	int getTime();
	int getMoney();
	int getIntelligence();
	int setName(string nameIn);
	string getName();
	int getStepsRemaining();
	int totalPoints(); 
private:
	string name;
	int stepsRemaining;
	int time;
	int money;
	int intelligence;
};

class Encounter {
public:
	Encounter();
	int decideEncounter(Character& character);
	int noEncounter();
	int choosePuzzle();
	int choosePuzzleReward(Character& character);
	int choosePuzzlePunishment(Character& character);
	int encounterPuzzle(Character& character);
	int encounterProfessor(Character& character);
	int encounterStudent(Character& character);
	int encounterGruntWork(Character& character);
	int encounterPapersToGrade(Character& character);
	int encounterText(Character& character);
private:
	string answer;
};

class Highscore {
public:
	Highscore();
	int fillArrays();
	int findMinimum();
	int addUser(string nameIn, int scoreIn);
	int readfile();
	int writefile(Character character);
	int sort();
private:
	string nameArray[ARRAY_MAX];
	int scoreArray[ARRAY_MAX];
	int minimum;
};

class Menu {
public:
	Menu();
	int welcomeMessage();
	int optionsMenu();
	int startGame();
	int howToPlay();
	int quitToOptionsMenu();
	int quitToWelcomeMessage();
	int inGameOptions();
	int move();
	int readPaper();
	int pickpocket();
	int viewCharacter();
	int youLose();
	int youWin();
private:
	Encounter encounter;
	Highscore highscore;
	Character character;
	bool hasSpace;
	string name;
};


/*
CONSTRUCTORS
*/

Character::Character() { 
	name = "NO_NAME";
	time = 25;
	intelligence = 10;
	money = 10;
	stepsRemaining = 20;
}

Menu::Menu() {
	// empty constructor
}


Encounter::Encounter() {
	// empty constructor
}

Highscore::Highscore() {
	// empty constructor
}




/*
Character member functions 
*/

bool Character::wonGame() {
	bool result = false;

	if (stepsRemaining == 0) {
		result = true;
	}

	return result;
}

bool Character::alive() {
	bool result = true;

	if (time <= 0 || money <= 0 || intelligence <= 0) {
		result = false;
	}

	return result;
}

int Character::changeTime(int difference) { 
	time = time + difference;

	return 0;
}

int Character::changeMoney(int difference) {
	money = money + difference;

	return 0;
}

int Character::changeIntelligence(int difference) {
	intelligence = intelligence + difference;

	return 0;
}

int Character::decrementSteps() {
	stepsRemaining--;

	return 0;
}

int Character::getTime() {
	return time;
}

int Character::getMoney() {
	return money;
}

int Character::getIntelligence() {
	return intelligence;
}

int Character::setName(string nameIn) {
	name = nameIn;

	return 0;
}

string Character::getName() {
	return name;
}

int Character::getStepsRemaining() {
	return stepsRemaining;
}

int Character::totalPoints() {
	int total;
	
	total = getTime() * getMoney() * getIntelligence();

	return total;
}




/*
Encounter member functions 
*/

int Encounter::decideEncounter(Character& character) {
	int chance = rand() % 100 + 1; // random number between 1 and 100

	character.changeTime(-1);
	cout << "\nYou move forward one step, and...\n\n";

	if (chance <= 25) {
		noEncounter();
	}
	else if (chance <= 50 && chance > 25) {
		encounterPuzzle(character);
	}
	else if (chance <= 60 && chance > 50) {
		encounterProfessor(character);
	}
	else if (chance <= 70 && chance > 60) {
		encounterStudent(character);
	}
	else if (chance <= 85 && chance > 70) {
		encounterGruntWork(character);
	}
	else if (chance <= 95 && chance > 85) {
		encounterPapersToGrade(character);
	}
	else {
		encounterText(character);
	}

	return 0;
}

int Encounter::noEncounter() {
	cout << "Nothing happens!\n";
	return 0;
}

int Encounter::choosePuzzle() {
	int value = rand() % 31;

	switch (value) {
	case 0:
		cout << "Who was the 1st President of the United States?\n";
		cout << "Please answer with only their last name.\n";
		answer = "WASHINGTON";
		break;
	case 1:
		cout << "Who was the 16th President of the United States?\n";
		cout << "Please answer with only their last name.\n";
		answer = "LINCOLN";
		break;
	case 2:
		cout << "Who was the 3rd President of the United States?\n";
		cout << "Please answer with only their last name.\n";
		answer = "JEFFERSON";
		break;
	case 3:
		cout << "Who was the oldest United States President to be inaugurated?\n";
		cout << "Please answer with only their last name.\n";
		answer = "TRUMP";
		break;
	case 4:
		cout << "What year was the United States of America founded?\n";
		answer = "1776";
		break;
	case 5:
		cout <<"What is the first word in the United States Constitution?\n";
		answer = "WE";
		break;
	case 6:
		cout << "Solve the following equation: 4 * 7 + 24 / 6 - 2\n";
		answer = "30";
		break;
	case 7:
		cout << "Solve the following equation: 18 / 4 - 1 / 2 + 2 * 3\n";
		answer = "10";
		break;
	case 8:
		cout << "Solve the following equation : 5 + 4 * 3 / 3 - 4\n";
		answer = "5";
		break;
	case 9:
		cout << "Solve the following equation : 6 / 4 - 1 + 10 / 4 + 12\n";
		answer = "15";
		break;
	case 10:
		cout << "Solve the following equation: 5 - 2 * 3 + 15 / 5 + 3\n";
		answer = "5";
		break;
	case 11:
		cout << "You have 17 carrots, 22 tomatoes, and 13 onions. How many vegetables do you have in total?\n";
		answer = "30";
		break;
	case 12:
		cout << "You have 23 apples, 4 tomatoes, and 13 oranges. How many fruits do you have in total?\n";
		answer = "40";
		break;
	case 13:
		cout << "You're facing west.\n";
		cout << "You turn 180 degrees clockwise.\n";
		cout << "You then turn 270 degrees counterclockwise.\n";
		cout << "What direction are you facing?\n";
		answer = "SOUTH";
		break;
	case 14:
		cout << "You're facing south.\n";
		cout << "You turn 90 degrees counterclockwise.\n";
		cout << "You then turn 540 degrees clockwise.\n";
		cout << "What direction are you facing?\n";
		answer = "WEST";
		break;
	case 15:
		cout << "You're facing north.\n";
		cout << "You turn 270 degrees clockwise.\n";
		cout << "You then turn 180 degrees clockwise.\n";
		cout << "What direction are you facing?\n";
		answer = "EAST";
		break;
	case 16:
		cout << "You're facing south.\n";
		cout << "You turn 270 degrees counterclockwise.\n";
		cout << "You then turn 270 degrees counterclockwise.\n";
		cout << "What direction are you facing?\n";
		answer = "NORTH";
		break;
	case 17:
		cout << "What's the most abundant element in the atmosphere?\n";
		answer = "NITROGEN";
		break;
	case 18:
		cout << "What's the most abundant element on earth?\n";
		answer = "OXYGEN";
		break;
	case 19:
		cout << "Plants get their energy from sunlight. What is this process called?\n";
		answer = "PHOTOSYNTHESIS";
		break;
	case 20:
		cout << "What is the functional opposite of condensation?\n";
		answer = "EVAPORATION";
		break;
	case 21:
		cout << "At what temperature, in Celcius, will water begin to freeze?\n";
		answer = "0";
		break;
	case 22:
		cout << "At what temperature, in Celcius, will water begin to boil?\n";
		answer = "100";
		break;
	case 23:
		cout << "If you melt 10g of ice in 60g of water, how many grams of water will you end up with?\n";
		answer = "70";
		break;
	case 24:
		cout << "Ignoring air resistance, about how many meters per second will an object accelerate due to gravity on Earth?\n";
		cout << "Round to the nearest tenth.\n";
		answer = "9.8";
		break;
	case 25:
		cout << "The words \"racecar\", \"kayak\", \"level\", and \"mom\" are examples of what kind of word?\n";
		answer = "PALINDROME";
		break;
	case 26:
		cout << "The sentence \"Carrie's cat clawed her couch, creating chaos\" uses what literary stylistic device?\n";
		answer = "ALLITERATION";
		break;
	case 27:
		cout << "The sentence \"He drowned in a sea of grief\" uses what literary stylistic device?\n";
		answer = "METAPHOR";
		break;
	case 28:
		cout << "The sentence \"He was like a ray of sunshine\" uses what literary stylistic device?\n";
		answer = "SIMILE";
		break;
	case 29:
		cout << "\"To be or not to be\" is a phrase spoken in which of Shakespeare's plays?\n";
		answer = "HAMLET";
		break;
	case 30:
		cout << "Diamonds are made out of what element?\n";
		answer = "CARBON";
		break;
	}

	return 0;
}

int Encounter::choosePuzzleReward(Character& character) {
	int value = rand() % 9; // random number between 0 and 8

	switch (value) {
	case 0:
		character.changeIntelligence(3);
		cout << "You were rewarded with 3 intelligence!\n";
		break;
	case 1:
		character.changeIntelligence(4);
		cout << "You were rewarded with 4 intelligence!\n";
		break;
	case 2:
		character.changeIntelligence(5);
		cout << "You were rewarded with 5 intelligence!\n";
		break;
	case 3:
		character.changeMoney(3);
		cout << "You were rewarded with $3!\n";
		break;
	case 4:
		character.changeMoney(4);
		cout << "You were rewarded with $4!\n";
		break;
	case 5:
		character.changeMoney(5);
		cout << "You were rewarded with $5!\n";
		break;
	case 6:
		character.changeTime(1);
		cout << "You were rewarded with 1 extra minute!\n";
		break;
	case 7:
		character.changeTime(2);
		cout << "You were rewarded with 2 extra minutes!\n";
		break;
	case 8:
		character.changeTime(3);
		cout << "You were rewarded with 3 extra minutes!\n";
		break;
	}

	return 0;
}

int Encounter::choosePuzzlePunishment(Character& character) {
	int value = rand() % 9; // random number between 0 and 8

	switch (value) {
	case 0:
		character.changeIntelligence(-3);
		cout << "You lost 3 intelligence.\n";
		break;
	case 1:
		character.changeIntelligence(-4);
		cout << "You lost 4 intelligence.\n";
		break;
	case 2:
		character.changeIntelligence(-5);
		cout << "You lost 5 intelligence.\n";
		break;
	case 3:
		character.changeMoney(-3);
		cout << "You lost $3.\n";
		break;
	case 4:
		character.changeMoney(-4);
		cout << "You lost $4.\n";
		break;
	case 5:
		character.changeMoney(-5);
		cout << "You lost $5.\n";
		break;
	case 6:
		character.changeTime(-1);
		cout << "You lost 1 minute.\n";
		break;
	case 7:
		character.changeTime(-2);
		cout << "You lost 2 minutes.\n";
		break;
	case 8:
		character.changeTime(-3);
		cout << "You lost 3 minutes.\n";
		break;
	}

	return 0;
}

int Encounter::encounterPuzzle(Character& character) {
	string input;
	cout << "You encounter a puzzle! Make sure you type your answer in all CAPITAL LETTERS.\n\n";
	
	choosePuzzle();

	cin >> input;

	if (input == answer) {
		cout << "\nCORRECT!\n";
		choosePuzzleReward(character);
	}
	else {
		cout << "\nINCORRECT!\n";
		choosePuzzlePunishment(character);
	}
	return 0;
}

int Encounter::encounterProfessor(Character& character) {
	cout << "You encounter a professor! He starts talking to you...\n";
	int value = rand() % 4; // random number between 0 and 3

	switch (value) {
	case 0:
		cout << "\nBoring. What a waste. You didn't gain anything from that encounter.\n";
			break;
		case 1:
		character.changeIntelligence(1);
		cout << "\nHe wasn't very interesting, but at least you got something from what he said.\n";
		cout << "You gained 1 intelligence!\n";
		break;
	case 2:
		character.changeIntelligence(2);
		cout << "\nWhat a thoughtful guy! You learned something today.\n";
		cout << "You gained 2 intelligence!\n";
		break;
	case 3:
		character.changeIntelligence(3);
		cout << "\nAbsolutely brilliant! This professor astounds you with his wisdom.\n";
		cout << "You gained 3 intelligence!\n";
		break;
	default:
		cout << "\nERROR: THIS LINE SHOULD NOT BE ABLE TO BE READ.\n";
	}

	return 0;
}

int Encounter::encounterStudent(Character& character) {
	cout << "You encounter another student! They approach you... \n";
	int value = rand() % 3; // random number between 0 and 2

	switch (value) {
	case 0:
		cout << "\nThey walk right past you. Whew! That was a close one.\n";
		break;
	case 1:
		character.changeTime(-1);
		cout << "\nThey briefly stop to say hello. You didn't ask for this...\n";
		cout << "You lost 1 minute.\n";
		break;
	case 2:
		character.changeTime(-2);
		cout << "\nThey start making a conversation with you. It drags on...\n";
		cout << "Could this get any worse?\n";
		cout << "You lost 2 minutes.\n";
		break;
	default:
		cout << "\nERROR: THIS LINE SHOULD NOT BE ABLE TO BE READ.\n";
	}

	return 0;
}

int Encounter::encounterGruntWork(Character& character) {
	cout << "You remember that you have some grunt work you need to take care of!\n";
	int value = rand() % 3; // random number between 0 and 2

	switch (value) {
	case 0:
		cout << "\nWell, that wasn't so bad. Onwards!\n";
		break;
	case 1: 
		character.changeIntelligence(-1);
		cout << "\nThat was pretty mindless work. You feel a little slow in the head now.\n";
		cout << "You lost 1 intelligence.\n";
		break;
	case 2:
		character.changeIntelligence(-2);
		cout << "\nThat work was so mindless that you actually feel more stupid than ever.\n";
		cout << "You lost 2 intelligence.\n";
		break;
	default:
		cout << "\nERROR: THIS LINE SHOULD NOT BE ABLE TO BE READ.\n";
	}

	return 0;
}

int Encounter::encounterPapersToGrade(Character& character) {
	cout << "You encounter a student! They ask you to critique their paper.\n";
	int value = rand() % 5; // random number between 0 and 4

	switch (value) {
	case 0:
		character.changeMoney(1);
		cout << "\nThey only tipped you $1. Sad...\n";
		break;
	case 1:
		character.changeMoney(2);
		cout << "\nThey tipped you $2. Could've been better...\n";
		break;
	case 2:
		character.changeMoney(3);
		cout << "\nThey tipped you $3. Nice!\n";
		break;
	case 3:
		character.changeMoney(4);
		cout << "\nThey tipped you $4. Amazing!\n";
		break;
	case 4:
		character.changeMoney(5);
		cout << "\nThey tipped you $5! What a hero!\n";
		break;
	default:
		cout << "\nERROR: THIS LINE SHOULD NOT BE ABLE TO BE READ.\n";
	}
	return 0;
}

int Encounter::encounterText(Character& character) {
	cout << "You get a text message! It's from your friend.\n";
	int value = rand() % 2; // random number between 0 and 1

	switch (value) {
	case 0:
		character.changeTime(3);
		cout << "\nYour friend tells you that your next class is cancelled. Neat!\n";
		cout << "You gained 3 minutes!\n";
		break;
	case 1:
		character.changeTime(5);
		cout << "\nYour friend tells you that the rest of your classes are cancelled for the day.\n";
		cout << "This is exactly what you wanted to hear!\n";
		cout << "You gained 5 minutes!\n";
		break;
	default:
		cout << "\nERROR: THIS LINE SHOULD NOT BE ABLE TO BE READ.\n";
	}

	return 0;
}






/*
Highscore member functions
*/

int Highscore::fillArrays() {
	ifstream inStream;
	inStream.open("highscores.txt");

	if (inStream.fail()) {
		return 0;
	}

	for (int i = 0; i < ARRAY_MAX; i++) {
		inStream >> nameArray[i] >> scoreArray[i];
	}

	return 0;
}

int Highscore::findMinimum() {
	minimum = scoreArray[0];

	for (int i = 1; i < ARRAY_MAX; ++i) {
		if (scoreArray[i] < minimum) {
			minimum = scoreArray[i];
		}
	}

	for (int j = 0; j < ARRAY_MAX; j++) {
		if (scoreArray[j] == minimum) {
			return j; // return index of minimum
		}
	}

	return 0;
}

int Highscore::addUser(string nameIn, int scoreIn) {
	int index = findMinimum();
	if (scoreIn > minimum) {
		scoreArray[index] = scoreIn;
		nameArray[index] = nameIn;
	}

	return 0;
}

int Highscore::readfile() {
	ifstream inStream;
	int numScores = 0;
	string line;

	inStream.open("highscores.txt");

	if (inStream.fail()) {
		cout << "\nHigh scores could not be read. Sorry!\n" << endl;
		return 0;
	}

	bool isEmpty = (inStream.peek() == ifstream::traits_type::eof());
	if (isEmpty) { 
		cout << "\nTop 10 High Scores:\n";
		cout << "\tNo scores have been recorded yet!\n";
		return 0;
	}

	cout << "\nTop 10 High Scores:\n";

	while (getline(inStream, line)) {
		numScores++;
		cout << "\t" << numScores << ". " << line << "\n";
	}

	inStream.close();
	return 0;
}


int Highscore::writefile(Character character) {
	ofstream outStream;

	sort();

	outStream.open("highscores.txt");

	for (int i = 0; i < ARRAY_MAX; i++) {
		outStream << nameArray[i] << "   " << scoreArray[i] << "\n";
	}

	outStream.close();
	return 0;
}

int Highscore::sort() {
	int tempScore;
	string tempName;

	for (int i = 0; i < ARRAY_MAX; i++) {
		for (int j = 0; j < ARRAY_MAX - 1; j++) {
			if (scoreArray[j] < scoreArray[j + 1]) {
				// swap scores
				tempScore = scoreArray[j];
				scoreArray[j] = scoreArray[j + 1];
				scoreArray[j + 1] = tempScore;
				// swap names as well
				tempName = nameArray[j];
				nameArray[j] = nameArray[j + 1];
				nameArray[j + 1] = tempName;
			}
		}
	}

	return 0;
}




/*
Menu member functions 
*/

int Menu::welcomeMessage() {
	cout << "\nWhat's your name? Please do not include any spaces: ";

	do {
		hasSpace = false;
		getline(cin, name);

		int nameSize = name.length();

		for (int i = 0; i < nameSize; i++) {
			if (name.at(i) == ' ') {
				hasSpace = true;
			}
		}

		if (name == "") {
			hasSpace = true;
		}

		if (hasSpace) {
			cout << "\nPlease do not include any spaces in your name. All other characters are fine.";
			cout << "\nEnter your name: ";
		}
	} while (hasSpace);

	character.setName(name);
	cout << "\n~~~Welcome to Shelby Hall, " << character.getName() << "!~~~\n";

	optionsMenu();

	return 0;
}

int Menu::optionsMenu() {
	string input;
	int inputInt;
	bool repeat;

	cout << "\n1) Start a New Game";
	cout << "\n2) How to Play";
	cout << "\n3) View High Scores";
	cout << "\n4) Quit";
	cout << "\n\nChoose an option (1, 2, 3, or 4): ";

	do {
		cin >> input;
		inputInt = atoi(input.c_str());
		repeat = false;

		switch (inputInt) {
		case 1:
			startGame();
			break;
		case 2:
			howToPlay();
			repeat = true;
			cout << "\n1) Start a New Game";
			cout << "\n2) How to Play";
			cout << "\n3) View High Scores";
			cout << "\n4) Quit";
			cout << "\n\nChoose an option (1, 2, 3, or 4): ";
			break;
		case 3:
			highscore.readfile();
			repeat = true;
			cout << "\n1) Start a New Game";
			cout << "\n2) How to Play";
			cout << "\n3) View High Scores";
			cout << "\n4) Quit";
			cout << "\n\nChoose an option (1, 2, 3, or 4): ";
			break;
		case 4:
			quitToOptionsMenu();
			break;
		default:
			cout << "Your input was invalid. Please enter a valid input (1, 2, 3, or 4): ";
			repeat = true;
		}
	} while (repeat);

	return 0;
}

int Menu::startGame() {
	cout << "\nEntering Shelby Hall...\n";
	inGameOptions();
	return 0;
}

int Menu::howToPlay() {
	cout << "\n~~~HOW TO PLAY~~~";
	cout << "\n\nAttributes:\n";
	cout << "\t - Once you've entered a game, you will begin your 20-step journey through Shelby Hall. "
		<< "\n\t - You will have three attributes: intelligence, money (displayed in dollars), and time (displayed in minutes). "
		<< "\n\t - If any of these attributes reaches 0 at any point, you lose the game. "
		<< "\n\t - If an attribute hits 0 on the same turn that you reach the end, you'll still lose the game; be wary!\n\n";
	
	cout << "Actions:\n";
	cout << "\t - You can choose to move, read technical papers, pickpocket a passerby, view character stats, or quit the game. "
		<< "\n\t - Moving, reading, and pickpocketing will all reduce your remaining time by 1. "
		<< "\n\t - However, viewing your character stats will not. Feel free to check your stats often! "
		<< "\n\t - Only moving your character will reduce the number of steps needed to reach the end. "
		<< "\n\t - If you successfully reach the end, then you win!\n\n";
	cout << "Moving:\n";
	cout << "\t - Moving your character could result in a number of different scenarios. "
		<< "\n\t - For example, you could encounter a puzzle in which you need to input the correct answer. "
		<< "\n\t - In this case, if you answer the question correctly, you will gain a random amount of a random attribute. "
		<< "\n\t - If you answer the question incorrectly, you will lose a random amount of a random attribute. "
		<< "\n\t - A number of other things that affect your attributes could also occur; you never know what'll happen! "
		<< "\n\t - Be careful and try to make sure that no single attribute is too low, or you might lose the game!\n\n";
	cout << "High scores:\n";
	cout << "\t - Your high score is calculated by multiplying your three attributes together at the end of the game. "
		<< "\n\t - If you lose the game, then your high score won't be calculated at all. "
		<< "\n\t - If your score is within the top 10, then it will be saved and will be shown on the high scores page.\n\n";
	cout << "Good luck, and have fun!\n";
	
	return 0;
}

int Menu::quitToOptionsMenu() {
	string input;
	bool repeat = true;

	cout << "\nAre you sure you want to quit? (Y/N): ";

	do {
		cin >> input;

		if (input == "Y" || input == "y") {
			cout << "\nThanks for playing!\n";
			cout << "Exiting program... \n";
			exit(1);
		}
		else if (input == "N" || input == "n") {
			optionsMenu();
			repeat = false;
		}
		else {
			cout << "Please enter a valid input (Y or N): ";
		}
	} while (repeat);

	return 0;
}

int Menu::quitToWelcomeMessage() {
	string input;
	bool repeat = true;

	cout << "\nAre you sure you want to quit? (Y/N): ";

	do {
		cin >> input;

		if (input == "Y" || input == "y") {
			cout << "\nThanks for playing!\n";
			cout << "Exiting program... \n";
			exit(1);
		}
		else if (input == "N" || input == "n") {
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			welcomeMessage();
			repeat = false;
		}
		else {
			cout << "Please enter a valid input (Y or N): ";
		}
	} while (repeat);

	return 0;
}

int Menu::inGameOptions() {
	string input;
	int inputInt;


	cout << "\nYou're " << character.getStepsRemaining() << " steps away from the end of the hall.";
	cout << "\n\t1) Move forward";
	cout << "\n\t2) Read technical papers";
	cout << "\n\t3) Pickpocket a passerby";
	cout << "\n\t4) View character stats";
	cout << "\n\t5) Quit game";
	cout << "\n\nChoose an action: ";

	do {
		if (!character.alive()) {
			youLose();
		}

		cin >> input;
		inputInt = atoi(input.c_str());

		switch (inputInt) {
		case 1:
			move();
			character.decrementSteps();

			if (character.getStepsRemaining() == 1) {
				if (!character.alive()) {
					youLose();
				}

				cout << "\nYou're " << character.getStepsRemaining() << " step away from the end of the hall.";
			}
			else if (character.getStepsRemaining() == 0) {
				if (!character.alive()) {
					youLose();
				}

				cout << "\nCongratulations! You reached the end!";
				break;
			}
			else {
				if (!character.alive()) {
					youLose();
				}

				cout << "\nYou're " << character.getStepsRemaining() << " steps away from the end of the hall.";
			}

			cout << "\n\t1) Move forward";
			cout << "\n\t2) Read technical papers";
			cout << "\n\t3) Pickpocket a passerby";
			cout << "\n\t4) View character stats";
			cout << "\n\t5) Quit game";
			cout << "\n\nChoose an action: ";
			break;
		case 2:
			readPaper();

			if (!character.alive()) {
				youLose();
			}

			if (character.getStepsRemaining() == 1) {
				cout << "\nYou're " << character.getStepsRemaining() << " step away from the end of the hall.";
			}
			else {
				cout << "\nYou're " << character.getStepsRemaining() << " steps away from the end of the hall.";
			}

			cout << "\n\t1) Move forward";
			cout << "\n\t2) Read technical papers";
			cout << "\n\t3) Pickpocket a passerby";
			cout << "\n\t4) View character stats";
			cout << "\n\t5) Quit game";
			cout << "\n\nChoose an action: ";
			break;
		case 3:
			pickpocket();

			if (!character.alive()) {
				youLose();
			}

			if (character.getStepsRemaining() == 1) {
				cout << "\nYou're " << character.getStepsRemaining() << " step away from the end of the hall.";
			}
			else {
				cout << "\nYou're " << character.getStepsRemaining() << " steps away from the end of the hall.";
			}

			cout << "\n\t1) Move forward";
			cout << "\n\t2) Read technical papers";
			cout << "\n\t3) Pickpocket a passerby";
			cout << "\n\t4) View character stats";
			cout << "\n\t5) Quit game";
			cout << "\n\nChoose an action: ";
			break;
		case 4:
			viewCharacter();
			cout << "\nChoose an action: ";
			break;
		case 5: {
			string inputCaseFive;
			bool repeatCaseFive = true;

			cout << "\nAre you sure? (Y/N): ";

			do {
				cin >> inputCaseFive;

				if (inputCaseFive == "Y" || inputCaseFive == "y") {
					cout << "\nCouldn't take the heat, huh?";
					cout << "\nWhat a pathetic way to go out. Oh well...\n";
					youLose();
				}
				else if (inputCaseFive == "N" || inputCaseFive == "n") {
					inGameOptions();
				}
				else {
					cout << "Please enter a valid input (Y or N): ";
				}
			} while (repeatCaseFive);
			break;
		}
		default:
			cout << "Your input was invalid. Please enter a valid input (1, 2, 3, 4, or 5): ";
		} 
	} while (!character.wonGame());

	youWin();

	return 0;
}

int Menu::move() {
	encounter.decideEncounter(character);
	
	return 0;
}

int Menu::readPaper() {
	
	character.changeTime(-1);
	cout << "\nYou decide to read some technical papers that you have on-hand.\n";
	int value = rand() % 5; // random number between 0 and 4

	switch (value) {
	case 0:
		character.changeIntelligence(1);
		cout << "\nNot the most exciting material, but you learned a little bit.\n";
		cout << "You gained 1 intelligence!\n";
		break;
	case 1:
		character.changeIntelligence(2);
		cout << "\nThis information might be useful.\n";
		cout << "You gained 2 intelligence!\n";
		break;
	case 2:
		character.changeIntelligence(3);
		cout << "\nYou learned something new!\n";
		cout << "You gained 3 intelligence!\n";
		break;
	case 3:
		character.changeIntelligence(4);
		cout << "\nThis information is riveting!\n";
		cout << "You gained 4 intelligence!\n";
		break;
	case 4:
		character.changeIntelligence(5);
		cout << "\nWow! Absolutely enthralling! You feel like a new person.\n";
		cout << "You gained 5 intelligence!\n";
		break;
	default:
		cout << "\nERROR: THIS LINE SHOULD NOT BE ABLE TO BE READ.\n";
	}

	return 0;
}

int Menu::pickpocket() {
	character.changeTime(-1);
	cout << "\nYou decide to pickpocket a passerby. Someone walks by...\n";
	int value = rand() % 8; // random number between 0 and 7

	switch (value) {
	case 0:
		cout << "\nYou can't spot their wallet. You pretend that nothing happened as they pass by.\n";
		cout << "You're disappointed. This was a waste of time.\n";
		break;
	case 1:
		character.changeMoney(1);
		cout << "\nYou snatch their wallet. There's $1 inside. Not much...\n";
		cout << "You gained $1!\n";
		break;
	case 2:
		character.changeMoney(2);
		cout << "\nYou snatch their wallet. There's $2 inside. Could be better...\n";
		cout << "You gained $2!\n";
		break;
	case 3:
		character.changeMoney(3);
		cout << "\nYou snatch their wallet. There's $3 inside. Decent!\n";
		cout << "You gained $3!\n";
		break;
	case 4:
		character.changeMoney(4);
		cout << "\nYou snatch their wallet. There's $4 inside. Hey, that's pretty good!\n";
		cout << "You gained $4!\n";
		break;
	case 5:
		character.changeMoney(5);
		cout << "\nYou snatch their wallet. There's a $5 bill inside. Nice!\n";
		cout << "You gained $5!\n";
		break;
	case 6:
		character.changeMoney(10);
		cout << "\nYou snatch their wallet. There's a $10 bill inside. Wow, that's more than you make in an hour!\n";
		cout << "You gained $10!\n";
		break;
	case 7:
		cout << "\nYou snatch their wallet. There's just a debit card and some receipts inside...\n";
		cout << "You're disappointed. This wasn't worth the risk.\n";
		break;
	default:
		cout << "\nERROR: THIS LINE SHOULD NOT BE ABLE TO BE READ.\n";
	}

	return 0;
}

int Menu::viewCharacter() {
	cout << "\nCharacter statistics:";
	cout << "\n\tIntelligence: " << character.getIntelligence(); 
	cout << "\n\tMoney: $" << character.getMoney();
	cout << "\n\tMinutes left: " << character.getTime() << "\n";
	return 0;
}

int Menu::youLose() {
	string input;
	bool repeat = true;
	
	if (character.getMoney() <= 0) {
		cout << "\nYou ran out of money! Now that you're impoverished, what point is there to continue living?";
		cout << "\nYou lived a good life, but all good things must come to an end.\n";
	}
	else if (character.getTime() <= 0) {
		cout << "\nYou ran out of time! You feel so rushed that you trip and fall to your demise.";
		cout << "\nIt was a sad way to go...\n";
	}
	else if (character.getIntelligence() <= 0) {
		cout << "\nYou ran out of intelligence! You can't even remember how to move anymore.";
		cout << "\nYou stand in place until you face your inevitable end. No one comes to your aid...\n";
	}

	cout << "\nYOU DIE.";
	cout << "\nReturn to main menu? (Y/N): ";

	do {
		cin >> input;

		if (input == "Y" || input == "y") {
			character = Character();
			cout << "\nReturning to main menu...\n";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			welcomeMessage();
			repeat = false;
		}
		else if (input == "N" || input == "n") {
			character = Character();
			quitToWelcomeMessage();
			repeat = false;
		}
		else {
			cout << "Please enter a valid input (Y or N): ";
		}
	} while (repeat);

	return 0;
}

int Menu::youWin() {
	string input;
	bool repeat = true;

	cout << "\nYOU WIN!";
	cout << "\nYour name: " << character.getName();
	cout << "\nYour score: " << character.totalPoints();

	highscore.fillArrays();
	highscore.addUser(character.getName(), character.totalPoints());
	highscore.writefile(character);
	cout << "\n";
	highscore.readfile();

	cout << "\nReturn to main menu? (Y/N): ";

	do {
		cin >> input;

		if (input == "Y" || input == "y") {
			character = Character();
			cout << "\nReturning to the options menu...\n";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			welcomeMessage();
			repeat = false;
		}
		else if (input == "N" || input == "n") {
			character = Character();
			quitToWelcomeMessage();
			repeat = false;
		}
		else {
			cout << "Please enter a valid input (Y or N): ";
		}
	} while (repeat);

	return 0;
}



void test_name_entry(void) {
	Menu menu = Menu();
	menu.welcomeMessage(); // use either name with or without spaces
}

void test_options_menu(void) {
	Menu menu = Menu();
	menu.optionsMenu(); // select 1, 2, 3, 4, or an invalid input
}

void test_ingame_options(void) {
	Menu menu = Menu();
	menu.inGameOptions(); // select 1, 2, 3, 4, 5, or an invalid input 
}

void test_puzzle(void) {
	Encounter encounter = Encounter();
	Character character = Character();
	encounter.encounterPuzzle(character); // either correct answer (+ to attribute) or incorrect answer (- to attribute)
}

void test_end_of_game(void) {
	Menu menu = Menu();
	menu.youWin(); // either highscore will appear if it is high enough, or will be ignored if lower than top 10
}


int main() {
	srand(time(NULL));
	Menu menu = Menu();
	menu.welcomeMessage();
	return 0;
}