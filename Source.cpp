// Emily Foley
// ef2vr@mail.umkc.edu
// 08/29/19
// CS201R Program 1

#include <iostream>
#include <ctime>
using namespace std;

int die_roll() {
	int die_Value;
	do { die_Value = (rand() % 10);
	} while (die_Value <= 0 || die_Value >= 7);
	return die_Value;
}
char verify_choice(int whose_turn, int pot_value) {
	char user_Choice;
	if (whose_turn == 0) {
		cin >> user_Choice;
		while (user_Choice != 'r' && user_Choice != 'R' && user_Choice != 'h' && user_Choice != 'H') {
			cout << "\nYou must enter R or H" << endl << "	(R)oll again or (H)old? ";
			cin >> user_Choice;
		}
	}
	else {
		if (pot_value < 20) {
			user_Choice = 'R';
		}
		else {
			user_Choice = 'H';
		}
	}
	return user_Choice;
}
char play_again() {
	char user_Choice;
	cin >> user_Choice;
	while (user_Choice != 'y' && user_Choice != 'Y' && user_Choice != 'n' && user_Choice != 'N') {
		cout << "\nYou must enter Y or N" << endl << "	Play Again (Y)es or (N)o? ";
		cin >> user_Choice;
	}
	return user_Choice;
}

int main() {
	srand(time(0));
	char playAgain = 'Y', userChoice;
	int userScore, compScore, potValue;
	int turnValue = 0;
	// Program
	while (playAgain == 'Y' || playAgain == 'y') {
		userScore = 0; compScore = 0; potValue = 0;
		// Game
		while (userScore < 50 && compScore < 50) {
			// Output score
			cout << "\nScore  You : " << userScore << " Computer : " << compScore << endl << endl;
			// Output whose turn it is
			switch (turnValue) {
			case 0:
				cout << "Player's Turn" << endl;
				break;
			case 1:
				cout << "Computer's Turn" << endl;
				break;
			default:
				break;}
			// Turn
			while (true) {
				// Step 1. Roll the dice
				int dieValue = die_roll();
				cout << "Die Roll : " << dieValue;

				if (dieValue == 1) {
					turnValue = 1 - turnValue;
					cout << " >> BUST" << endl;
					potValue = 0;
					break;}
				else { // if rolled 2-6, HOLD or ROLL AGAIN
					potValue += dieValue;
					cout << "   Pot : " << potValue;
					if (turnValue == 0) { cout << "	(R)oll again or (H)old? ";}
					else { cout << endl; }
					userChoice = verify_choice(turnValue, potValue);
					// ROLL AGAIN return to step 1
					if (userChoice == 'r' || userChoice == 'R') {
						continue;}
					else { // HOLD
						if (turnValue == 0) {
							userScore += potValue;}
						else {
							compScore += potValue;}
						potValue = 0;
						turnValue = 1 - turnValue;
						break;}}
			}
		}
		// Output final score & winner
		cout << "\nScore  You : " << userScore << " Computer : " << compScore << endl;
		if (userScore > compScore) { cout << "You won!" << endl;}
		else if (userScore < compScore) { cout << "The computer won." << endl;}
		else { cout << "You tied with the computer." << endl;} 
		cout << "Do you want to play again? (Y)es or (N)o ";
		playAgain = play_again();
	}
	return 0;
}