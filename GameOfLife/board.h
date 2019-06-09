#pragma once
#include "cell.h"
#include "rle.h"
#include<omp.h>
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
	vector<vector<cell>> copy(vector<vector<cell>> p1);
public:
	board() {};
	board(int sizeMToAdd, int sizeNToAdd);
	int getSizeM();
	int getSizeN();
	bool getState(int i, int j);
	void setSizeM(int value);
	void setSizeN(int value);
	void setSizeMAndN(int valueM, int valueN);
	void nextStep();
	void birthBasedOnCordinates(int x, int y, int cellSize);
	void killBasedOnCordinates(int x, int y, int cellSize);
	void setState(int i, int j, bool stateToSet);
	void createBoardFromFile(string fileName);
	void createFileFromBoard(string fileName);
	shared_ptr<vector<vector<cell>>> returnBoard();
};

