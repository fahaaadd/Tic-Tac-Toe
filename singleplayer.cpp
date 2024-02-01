#include <iostream>
using namespace std;

bool checkWinner(int b[][3], int& who) {

	for (int r = 0; r < 3; r++) {
		if (b[r][0] == b[r][1] && b[r][0] == b[r][2] && b[r][0] != 0) {
			who = b[r][0];
			return true;
		}
		for (int c = 0; c < 3; c++) {
			if (b[0][c] == b[1][c] && b[0][c] == b[2][c] && b[0][c] != 0) {
				who = b[0][c];
				return true;
			}
		}

		if (b[0][0] == b[1][1] && b[0][0] == b[2][2] && b[0][0] != 0) {
			who = b[0][0];
			return true;
		}

		if (b[0][2] == b[2][2] && b[0][2] == b[2][0] && b[0][2] != 0) {
			who = b[0][2];
			return true;
		}

		return false;
	}
}



void printBoard(int board[][3], int row) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			if (board[i][j] == 1) {
				cout << "X ";
			}
			else if (board[i][j] == 2) {
				cout << "O ";
			}
			else
				cout << "_ ";
		}
		cout << endl;
	}
}

void updateBoard(int board[][3], int row, int col, int p)
{
	board[row][col] = p;
}

void calculate(int b[][3], int& r, int& c, int opp) {
	int who; bool w = false;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (b[i][j] == 0)
			{
				r = i; c = j;
				b[i][j] = opp;
				w = checkWinner(b, who);
				b[i][j] = 0;
			}
		}
	}
	if (w == false)
	{
		if (b[1][1] == 0) {
			r = 1;
			c = 1;
		}
		else if (b[0][0] == 0) {
			r = 0;
			r = 0;
		}
		else if (b[0][2] == 0) {
			r = 0;
			c = 2;
		}
		else if (b[2][0] == 0) {
			r = 2;
			c = 0;
		}
	}



}








int main()
{
	bool winner = 0;
	int board[3][3];
	int who;
	char p1 = 'O';
	char p2 = 'X';
	char empty = '_';

	for (int i = 0; i < 3; i++)				//initialise board
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = 0;
		}
	}

	printBoard(board, 3);
	int player = 1;
	int row, col;

	for (int i = 1; i <= 9 && winner == 0; i++) {

		if (player == 1)
		{
			calculate(board, row, col, 1);
			updateBoard(board, row, col, 1);

			player = 2;
		}
		else
		{
			cin >> row >> col;
			row--;
			col--;
			while (board[row][col] != 0 || row > 2 || col > 2 || row < 0 || col < 0) {
				cout << "Please enter again\n";
				cin >> row >> col;
				row--;
				col--;
			}
			updateBoard(board, row, col, 2);



			player = 1;
		}
		cout << endl;
		printBoard(board, 3);
		winner = checkWinner(board, who);

	}			//end of for	

	if (winner)
	{
		cout << endl << "The winner is " << who;
	}
	else
	{
		cout << "Draw";
	}

}
