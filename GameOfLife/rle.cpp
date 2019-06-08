#include "rle.h"

unique_ptr<string[]> encodeRLE(vector<vector<cell>> &toEncode) {
	int n = toEncode.size();
	if (n == 0)
		return nullptr;
	int m = toEncode[0].size();
	unique_ptr<string[]> result(new string[n]);
	for (int i = 0; i < n; i++) {
		for (int j = 0, count = 1; j < m-1; j++) {
			count = 1;
			while (j < m-1 && toEncode[i][j].returnState() == toEncode[i][j + 1].returnState()) {
				count++;
				j++;
			}
			result[i] += to_string(count);

			result[i] += toEncode[i][j].returnState() ? 'T' : 'F';

		}
	}
	return move(result);
}

vector<vector<cell>> decodeRLEdirectFromFile(string nameOfFile) {
	ifstream file(nameOfFile);
	if (file.bad())
		throw new exception();


	vector<string> lines;
	string line;
	cell tmpCell;
	int callingLine = 0;
	while (file >> line)
		lines.push_back(line);
	vector<vector<cell>> board(lines.size());//, vector<cell>(1));
	int result = 0, j = 1;
	bool state, boardCreated = false, stateOfPreviousOne;;
	stack<char> numberStack;
	int numberOfLine = 0;
	for (auto& tmp : lines) {
		cout << tmp << " ";
		while (tmp.size()) {
			if (tmp.back() == 'T') {
				j = 1;

				tmp.pop_back();
				if (!result) {
					continue;
				}
				else {
					
					for (int i = 0; i < result; i++) {
						tmpCell = new cell();
						state == true ? tmpCell.birth() : tmpCell.kill();
						auto it = board[callingLine].begin();
						board[callingLine].insert(it, tmpCell);
					}
					result = 0;
				}
				state = true;
			}
			else if (tmp.back() == 'F') {
				j = 1;

				tmp.pop_back();
				if (!result) {
					continue;
				}
				else {
					cout << "wpisuje do linii " << callingLine << " tyle " << result << " o wartoœci " << stateOfPreviousOne << " ";
					for (int i = 0; i < result; i++) {
						tmpCell = new cell();
						state == true ? tmpCell.birth() : tmpCell.kill();
						auto it = board[callingLine].begin();
						board[callingLine].insert(it, tmpCell);
					}
					cout << endl;
					result = 0;
				}
				state = false;
			}
			else {
				result += ((int)tmp.back() - 48)*j;
				j *= 10;
				tmp.pop_back();
				callingLine = numberOfLine;
				stateOfPreviousOne = state;
			}
		}
		numberOfLine++;
		cout << endl << endl;
	}
	for (int i = 0; i < result; i++) {
		tmpCell = new cell();
		tmpCell.kill();
		
		auto it = board[callingLine].begin();
		board[callingLine].insert(it, tmpCell);
	}
	
	file.close();
	for (auto& rows : board) {
		for (auto& element : rows)
			cout << element.returnState() << " ";
		cout << endl;
	}

	return board;
}
