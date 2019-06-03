#pragma once
#include "cell.h"
#include <vector>
using namespace std;
class board
{
private:
	int sizeM;
	int sizeN;
	int one = 1;
	vector<vector<cell>> mainBoard;
	vector<vector<cell>> copyOfMainBoard;
	int mod(int x, int max);
public:
	board();
	int getSizeM();
	int getSizeN();
	bool getState(int i, int j);
	void setSizeM(int value);
	void setSizeN(int value);
	void nextStep();
};

