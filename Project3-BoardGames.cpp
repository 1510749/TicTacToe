//File: Project3-BoardGames.cpp
//Date: 12/4/2018
//Course: CompSci 1
//Description:  This program will be a simple game of tic-tac-toe
//Usage:  This program will ask the user for input for playing the game and navigating menus. That is all.

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>
#include <string>
#include <sstream>

using namespace std;

class TicTacToe {
	public:		
		string board[3][3] = { {"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"} };
		string winner;
		string player_symbol;
		string c_symbol;
		string cmove;
		int turn;
		string response;
		void printBoard();
		void play();
		void resetBoard();
		string win_check();
};

void TicTacToe::resetBoard() {
	board[0][0] = "1";
	board[0][1] = "2";
	board[0][2] = "3";
	board[1][0] = "4";
	board[1][1] = "5";
	board[1][2] = "6";
	board[2][0] = "7";
	board[2][1] = "8";
	board[2][2] = "9";
}

void TicTacToe::printBoard() {
	for (int i = 0; i < 3; i++) {
		cout << "  " << board[i][0] << "  " << board[i][1] << "  " << board[i][2] << endl << endl;
	}
}

void TicTacToe::play() {
	//remember to clear terminal when appropriate
	bool temp = false;
	int temp2 = 0;
	printBoard();
	if (turn == 0) {
		while(temp == false) {
			cout << "Pick a spot: ";
			cin >> response;
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if((board[j][k] != "X") && (board[j][k] != "O") && (board[j][k] == response)){
						board[j][k] = player_symbol;
						temp = true;
						break;
						//cout << "Invalid spot" << endl;
					}
					//if ((board[j][k] == response)) {
					//	board[j][k] = player_symbol;
					//	temp = true;
					//}
					
				}
			}
			cout << "Invalid spot" << endl;
		}
		printf("\033c");
		printBoard();
		Sleep(1500);
		printf("\033c");
		turn = 1;
	}
	else if (turn == 1) {
		cout << "The computer is making a move..." << endl;
		Sleep(1650);
		while (!temp) {
			srand(time(0));
			temp2 = (rand() % 9) + 1;
			//convert cmove to a string
			//stringstream(temp2) >> cmove;
			cmove = to_string(temp2);
			
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if ((board[j][k] == cmove)) {
						board[j][k] = c_symbol;
						temp = true;
					}
				}
			}
		}
		printf("\033c");
		printBoard();
		//cout << "computer moved: " << cmove << endl;
		Sleep(1650);
		printf("\033c");
		turn = 0;
	}
}

string TicTacToe::win_check() {
	bool temp = false;
	//horizontals
	if ((board[0][0] == board[0][1]) && (board[0][1] == board[0][2])) {
		winner = board[0][1];
		temp = true;
	}
	else if ((board[1][0] == board[1][1]) && (board[1][1] == board[1][2])) {
		winner = board[1][1];
		temp = true;
	}
	else if ((board[2][0] == board[2][1]) && (board[2][1] == board[2][2])) {
		winner = board[2][1];
		temp = true;
	}
	//verticals
	else if ((board[0][0] == board[1][0]) && (board[1][0] == board[2][0])) {
		winner = board[1][1];
		temp = true;
	}
	else if ((board[0][1] == board[1][1]) && (board[1][1] == board[2][1])) {
		winner = board[1][1];
		temp = true;
	}
	else if ((board[0][2] == board[1][2]) && (board[1][2] == board[2][2])) {
		winner = board[1][2];
		temp = true;
	}
	//diagonals
	else if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
		winner = board[1][1];
		temp = true;
	}
	else if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0])) {
		winner = board[1][1];
		temp = true;
	}

//Gameover messages
	if (temp == true) {
		printBoard();
		if (winner == player_symbol) {
			cout << right << setw(7)<< "You(" << player_symbol << ") have won!";
		}
		else if (winner == c_symbol) {
			cout << right << setw(7) << "The computer(" << c_symbol << ") has won!";
		}
		else { cout << "DRAW!"; }

		cout << endl << right << setw(10) << "1) Menu" << right << setw(10) << "2) Quit" << endl;
		cin >> response;
		while ((response != "1") && (response != "2")) {
			cout << "Invalid response" << endl;
			cin >> response;
		}
		return response;
	}
	return "10";
}

int main()
{
	TicTacToe Game;
//boooleans for navigation
	bool done = false;
	bool menu = true;
	bool playing = false;
	bool rules = false;
	bool playing_phase = false;


//running
	while (!done) {
//menu
		while (menu) {
			cout << right << setw(34) << "Welcome to Tic-Tac-Toe!" << endl << "---------------------------------------------" << endl;
			cout << right << setw(15) << "1) Play" << right << setw(11) << "2) Rules" << right << setw(10) << "3) Quit" << endl;
			Game.response = "0";
			//Game.resetBoard();
			while ((Game.response != "1") && (Game.response != "2") && (Game.response != "3")) {
				cin >> Game.response;
				if (Game.response == "1") {
					Game.resetBoard();
					playing = true;
					menu = false;
					printf("\033c");
					break;
				}
				else if (Game.response == "2") {
					rules = true;
					menu = false;
					printf("\033c");
					break;
				}
				else if (Game.response == "3") {
					return 0;
				}
				cout << "Invalid Response" << endl;
			}
		}
//rules
		while (rules) {
			cout << "Use your turn to place down a single marker." << endl << endl
				<< "The game board is three by three and you will play against an unintelligent computer." << endl << endl
				<< "Match three of your markers in a row, in any direction, to win the game." << endl << endl
				<< "Absolutely please do you best to refrain from spaces, characters, and symbols e.g. 'a, b, c, d, -, /,  , $, etc.'" << endl
				<< right << setw(15) << "1) Menu" << right << setw(10) << "2) Quit" << endl << endl;
			Game.response = "0";
			while ((Game.response != "1") && (Game.response != "2")) {
				cin >> Game.response;
				if (Game.response == "1") {
					rules = false;
					menu = true;
					printf("\033c");
					break;
				}
				else if (Game.response == "2") {
					return 0;
				}
				cout << "Invalid Response" << endl;
			}
		}
//playing/setup
		while(playing) {
			Game.response = "0";
			cout << right << setw(28) << "Pick your symbol: " << endl
				<< right << setw(15) << "1) X" << right << setw(10) << "2) O" << endl;
			while ((Game.response != "1") && (Game.response != "2")) {
				cin >> Game.response;
				if (Game.response == "1") {
					cout << endl << "You are 'X'!" << endl;
					Game.player_symbol = 'X';
					Game.c_symbol = 'O';
					break;
				}
				else if (Game.response == "2") {
					cout << endl << "You are 'O'!" << endl;
					Game.player_symbol = 'O';
					Game.c_symbol = 'X';
					break;
				}
				cout << "Invalid Response" << endl;
			}
//Who"s on First
			srand(time(0));
			Game.turn = (rand() % 2);
			if (Game.turn == 0) {
				cout << "You go first!" << endl << endl;
			}
			else {
				cout << "The computer goes first!" << endl << endl;
			}
			//PLAYING PHASE HERE
			playing_phase = true;
			while (playing_phase) {
				//Game.printBoard();
				Game.play();
				string over_choice = Game.win_check();

				if (over_choice == "1") {
					playing_phase = false;
					menu = true;
					playing = false;
					printf("\033c");
				}
				else if (over_choice == "2") {
					return 0;
				}
			}
			
		}
	}

}
