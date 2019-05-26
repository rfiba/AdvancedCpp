#include <iostream>
#include <vector>
#include <fstream>
#include "cell.h"
#include "rle.h"

using namespace std;

const int SIZE = 20;

int mod(int x, int max) {
	if (x >= 0 && x<max)
		return x;
	else if (x < 0)
		return max - 1;
	else
		return (x - max);

}

void prepare(vector<vector<cell>> &board1, vector<vector<cell>> &board2) {
	for (int i = 0; i < board1.size(); i++) {
		for (int j = 0; j < board1[i].size(); j++) {

			int alives = 0;
			bool flag1 = 0, flag2 = 0;
			(board1[mod(i - 1, SIZE)][j].returnState()) ? alives++ : 0;
			(board1[mod(i - 1, SIZE)][mod(j + 1, SIZE)].returnState()) ? alives++ : 0;
			(board1[mod(i - 1, SIZE)][mod(j - 1, SIZE)].returnState()) ? alives++ : 0;
			(board1[mod(i + 1, SIZE)][j].returnState()) ? alives++ : 0;
			(board1[mod(i + 1, SIZE)][mod(j + 1, SIZE)].returnState()) ? alives++ : 0;
			(board1[mod(i + 1, SIZE)][mod(j - 1, SIZE)].returnState()) ? alives++ : 0;
			(board1[i][mod(j + 1, SIZE)].returnState()) ? alives++ : 0;
			(board1[i][mod(j - 1, SIZE)].returnState()) ? alives++ : 0;

			if (board1[i][j].returnState()) {
				if (alives != 2 && alives != 3) {
					board2[i][j].kill();
					continue;
				}
			}
			else {
				if (alives == 3) {
					board2[i][j].birth();
					continue;
				}
			}

			board2[i][j] = board1[i][j];


		}
	}
}

int main() {
	vector<vector<cell>> board(SIZE, vector<cell>(SIZE));
	vector<vector<cell>> board2(SIZE, vector<cell>(SIZE));
	board[0][0].birth();
	board[0][1].birth();
	board[1][1].birth();
	board[1][0].birth();
	board[3][7].birth();
	board[4][7].birth();
	board[5][7].birth();
	board[5][6].birth();
	board[4][5].birth();

	//encodeRLE(board);
	decodeRLEdirectFromFile("board.rle");
	int i = 0;
	cin >> i;
	return 0;


	
	for (int i = 0; i < 10; i++) {
		(i % 2) ? prepare(board2, board) : prepare(board, board2);
		cout << endl << i << endl;
		if (i % 2) {

			for (auto& rows : board2) {
				for (auto& element : rows)
					cout << element.returnState() << " ";
				cout << endl;
			}
		}
		else {
			for (auto& rows : board) {
				for (auto& element : rows)
					cout << element.returnState() << " ";
				cout << endl;
			}
		}
	}

	ofstream file("board.rle", ofstream::trunc);
	if (file.bad())
		return 1;

	if (i % 2) {
		auto result = encodeRLE(board);
		for (int i = 0; i < SIZE; i++)
			file << result[i] << endl;
	}
	else {
		auto result = encodeRLE(board2);
		for (int i = 0; i < SIZE; i++)
			file << result[i] << endl;
	}

	file.close();

	return 0;
}