#include "cell.h"

cell::cell() {
	state = false;
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