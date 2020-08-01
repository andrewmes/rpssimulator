#include "Play.h"
#include <string>
#include <iostream>

using namespace std;

Play::Play()
{
}


Play::~Play()
{
}

void Play::introFunc()
{
	string name;
	cout << "Welcome to RPS! Please enter your name: " << endl;
	getline(cin, name);
	cout << endl << "Hello " << name << "! Let's Play!" << endl;
	cout << "I have made my choice! Make yours!" <<
		endl << "Enter 'rock' for Rock, 'paper' for Paper and 'scissors' for scissors." << endl;
}

void Play::rpcPlay()
{
	
		int userScore = 0;
		int compScore = 0;
		int userMove = 0;
		int tieRockCounter = 0;
		int tiePaperCounter = 0;
		int tieScissorsCounter = 0;
		char userAnswer;
		string userMoveWord;

		//random first move for computer, the rest will be calculated
		int compMove = rand() % 1 + 3;

		while (userScore < 3 && compScore < 3)
		{
			cout << endl << "Shoot!" << endl;

			getline(cin, userMoveWord);

			if (userMoveWord == "rock")
			{
				userMove = 1;
			}
			else if (userMoveWord == "paper")
			{
				userMove = 2;
			}
			else if (userMoveWord == "scissors")
			{
				userMove = 3;
			}

			//ties
			if (userMove == 1 && (compMove == 1))
			{
				cout << "I played Rock." << endl << "Tie." << endl;
				tieRockCounter++;
				if (tieRockCounter > 1)
				{
					compMove = rand() % 1 + 3;
				}
			}

			else if (userMove == 2 && (compMove == 2))
			{
				cout << "I played Paper." << endl << "Tie." << endl;
				tiePaperCounter++;
				if (tiePaperCounter > 1)
				{
					compMove = rand() % 1 + 3;
				}
			}

			else if (userMove == 3 && (compMove == 3))
			{
				cout << "I played Scissors." << endl << "Tie." << endl;
				tieScissorsCounter++;
				compMove = 1;
			}

			//rock wins
			else if (userMove == 1 && (compMove == 3))
			{
				cout << "I played Scissors." << endl << "You win with Rock!" << endl;
				userScore++;

				compMove = 2;
			}

			else if (compMove == 1 && (userMove == 3))
			{
				cout << "I played Rock." << endl << "I win with Rock!" << endl;
				compScore++;

				compMove = 3;
			}

			//paper wins
			else if (userMove == 2 && (compMove == 1))
			{
				cout << "I played Rock." << endl << "You win with Paper!" << endl;
				userScore++;

				compMove = 3;
			}

			else if (compMove == 2 && (userMove == 1))
			{
				cout << "I played Paper." << endl << "I won with Paper!" << endl;
				compScore++;

				compMove = 1;
			}

			//scissors wins
			else if (userMove == 3 && (compMove == 2))
			{
				cout << "I played Paper." << endl << "You win with Scissors." << endl;
				userScore++;

				compMove = 1;
			}

			else if (compMove == 3 && (userMove == 2))
			{
				cout << "I played Scissors." << endl << "I win with Scissors!" << endl;
				compScore++;

				compMove = 2;
			}
			else if (userMove != 1 && userMove != 2 && userMove != 3)
			{
				cout << "what are you doing?" << endl;
			}

			if (userScore == 3)
			{
				cout << "Congrats! You beat me!" << endl;
			}

			else if (compScore == 3)
			{
				cout << "I won! Better luck next time!" << endl;
			}
		}
		if (userScore == 3 || compScore == 3)
		{
			cout << "Do you want to play again? If so press 'y'" << endl;
			cin >> userAnswer;
			if (userAnswer == 'y')
			{
				cout << "Ok, I've made my move!" << endl;
				cin.get();
				rpcPlay();
			}
			else
			{
				cout << "Thanks for playing!" << endl;
				return;
			}
		}
	
}

