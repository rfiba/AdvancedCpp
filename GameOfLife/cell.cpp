#include "cell.h"
#include<iostream>

using namespace std;

cell::cell() {
	state = false;
}
cell::cell(bool stateToAdd) {
	//cout << stateToAdd << endl;
	state = stateToAdd;
	
}

void cell::kill() {
	state = 0;
}

void cell::birth() {
	state = 1;
}

bool cell::returnState() {
	return state;
}