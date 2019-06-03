#include "board.h"



int board::mod(int x, int max)
{
	if(x >= 0 && x<max)
		return x;
	else if (x < 0)
		return max - 1;
	else
		return (x - max);
}

board::board()
{
	vector<vector<cell>> p1(sizeM, vector<cell>(sizeN));
	mainBoard = p1;
	
}

int board::getSizeM()
{
	return sizeM;
}

int board::getSizeN()
{
	return sizeN;
}

bool board::getState(int i, int j)
{
	return mainBoard[i][j].returnState();
}

void board::setSizeM(int value)
{
	sizeM = value;
}

void board::setSizeN(int value)
{
	sizeN = value;
}

void board::nextStep()
{
	copyOfMainBoard = mainBoard;

	for (int i = 0; i < copyOfMainBoard.size(); i++) {
		for (int j = 0; j < copyOfMainBoard[i].size(); j++) {

			int alives = 0;
			bool flag1 = 0, flag2 = 0;
			(copyOfMainBoard[mod(i - 1, sizeM)][j].returnState()) ? alives++ : 0;
			(copyOfMainBoard[mod(i - 1, sizeM)][mod(j + 1, sizeN)].returnState()) ? alives++ : 0;
			(copyOfMainBoard[mod(i - 1, sizeM)][mod(j - 1, sizeN)].returnState()) ? alives++ : 0;
			(copyOfMainBoard[mod(i + 1, sizeM)][j].returnState()) ? alives++ : 0;
			(copyOfMainBoard[mod(i + 1, sizeM)][mod(j + 1, sizeN)].returnState()) ? alives++ : 0;
			(copyOfMainBoard[mod(i + 1, sizeM)][mod(j - 1, sizeN)].returnState()) ? alives++ : 0;
			(copyOfMainBoard[i][mod(j + 1, sizeN)].returnState()) ? alives++ : 0;
			(copyOfMainBoard[i][mod(j - 1, sizeN)].returnState()) ? alives++ : 0;

			if (copyOfMainBoard[i][j].returnState()) {
				if (alives != 2 && alives != 3) {
					mainBoard[i][j].kill();
					continue;
				}
			}
			else {
				if (alives == 3) {
					mainBoard[i][j].birth();
					continue;
				}
			}

			mainBoard[i][j] = copyOfMainBoard[i][j];
		}
	}
}
