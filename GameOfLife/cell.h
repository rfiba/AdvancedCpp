#pragma once
#ifndef CELL_H
#define CELL_H
class cell
{
private:
	bool state;
public:
	cell();
	cell(bool);
	void kill();
	void birth();
	bool returnState();
};
#endif
