// NOTE: This is a very rough-around-the-edges version of rock, paper, scissors. It has some problems, but it's functional, and primarily serves as a base for the text file code. 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	char player;
	bool anotherRound;
	int gamesPlayed = 0;
	int playerWinCount = 0;
	int compWinCount = 0;
	bool tie = false;
	enum input { rock, paper, scissors };
	input pick;
	string game;

	ofstream outfile;
	ifstream infile;


	cout << "Would you like to play Rock, Paper, Scissors? (Please press 'y' or 'n')" << endl;
	cin >> game;

	if (game == "y" || game == "Y")
	{
		anotherRound = true;
		gamesPlayed++;
		infile.open("RockPaperScissors.txt");
		infile >> playerWinCount >> compWinCount;
		infile.close();
	}
	else
	{
		anotherRound = false;
		cout << "Well fine then, I didn't want to play with you anyway! >:(" << endl;
		while (true) {}
	}

	while (anotherRound != false)
	{
		cout << "" << endl << "Do you wish to select rock ('r'), paper ('p'), or scissors ('s')?" << endl;
		cin >> player;
		cout << endl;


		if (player == 'r' || player == 'R')
		{
			pick = rock;
		}

		else if (player == 'p' || player == 'P')
		{
			pick = paper;
		}

		else if (player == 's' || player == 'S')
		{
			pick = scissors;
		}

		else
		{
			cout << "I'm sorry, I'm afraid that wasn't an option." << endl;
			cout << endl << endl << "Do you wish to select rock ('r'), paper ('p'), or scissors ('s')?" << endl;
			cin >> player;
		}

		int computer = rand();
		computer = rand() % 3;

		while (computer == pick)
		{
			cout << endl << "You both picked that one, so it was a tie. Please pick again. ('r', 'p', 's')" << endl;
			cin >> player;

			if (player == 'r' || player == 'R')
			{
				pick = rock;
			}

			else if (player == 'p' || player == 'P')
			{
				pick = paper;
			}

			else if (player == 's' || player == 'S')
			{
				pick = scissors;
			}

			else
			{
				cout << "I'm sorry, I'm afraid that wasn't an option." << endl;
				cout << endl << endl << "Do you wish to select rock ('r'), paper ('p'), or scissors ('s')?" << endl;
				cin >> player;
			}

			computer = rand() % 3;
		}


		input compChoice;

		if (computer == 0)
		{
			compChoice = rock;
		}

		else if (computer == 1)
		{
			compChoice = paper;
		}

		else if (computer == 2)
		{
			compChoice = scissors;
		}

		cout << "The computer chose " << compChoice << endl;

		if ((pick == rock && compChoice == scissors) || (pick == paper && compChoice == rock) || (pick == scissors && compChoice == paper))
		{
			cout << "" << endl << pick << " beats " << compChoice << ". You won!" << endl;
			playerWinCount++;
		}

		else if ((compChoice == rock && pick == scissors) || (compChoice == paper && pick == rock) || (compChoice == scissors && pick == paper))
		{
			cout << "" << endl << compChoice << " beats " << pick << ". The computer won." << endl;
			compWinCount++;
		}

		cout << "You have won " << playerWinCount << " time(s)." << endl;
		cout << "Your opponent has won " << compWinCount << " time(s)." << endl;

		cout << "" << endl << "Would you like to play again? (Please enter 'y' or 'n')" << endl;
		cin >> game;

		if (game == "n" || game == "N")
		{
			anotherRound = false;
		}
		else if (game == "y" || game == "Y")
		{
			gamesPlayed++;
		}

		outfile.open("RockPaperScissors.txt");
		outfile << gamesPlayed << " games played." << "\n";
		outfile << playerWinCount << " player victories." << "\n";
		outfile << compWinCount << " opponent victories." << "\n";
		outfile.close();
	}

	system("pause");

	fstream file;

	file.open("RockPaperScissors.txt");

	if (file.fail())
	{
		cout << "File not found." << endl;
		return -1;
	}

	string buffer;
	while (getline(file, buffer))
	{
		cout << buffer << endl;
	}

	file.clear();
	while (true) {}
	return 0;
}
