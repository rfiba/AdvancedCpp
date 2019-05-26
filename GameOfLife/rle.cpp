#include "rle.h"

unique_ptr<string[]> encodeRLE(vector<vector<cell>> &toEncode) {
	int n = toEncode.size();
	if (n == 0)
		return nullptr;
	int m = toEncode[0].size();
	unique_ptr<string[]> result(new string[n]);
	for (int i = 0; i < n; i++) {
		for (int j = 0, count = 1; j < m; j++) {
			count = 1;
			while (toEncode[i][j].returnState() == toEncode[i][j + 1].returnState()) {
				count++;
				j++;
			}
			result[i] += to_string(count);

			result[i] += toEncode[i][j].returnState() ? 'T' : 'F';

		}
	}
	return move(result);
}

void decodeRLEdirectFromFile(string nameOfFile) {
	ifstream file(nameOfFile);
	if (file.bad())
		throw new exception();

	
	vector<string> lines;
	string line;
	
	while (file >> line)
		lines.push_back(line);
	cout << lines.size() << endl;
	vector<vector<cell>> board(lines.size(), vector<cell>(1));
	int result = 0, j = 1;
	bool state, boardCreated = false;
	stack<char> numberStack;
	int numberOfLine = 0;
	for (auto& tmp : lines) {
		cout << tmp << " ";
		while (tmp.size()) {
			if (tmp.back() == 'T') {
				j = 1;
				state = true;
				tmp.pop_back();
				if (!result)
					continue;
				else {
					cout << result << "---";
					for (int i = 0; i < result; i++)
						board[numberOfLine].push_back(new cell(state));
					result = 0;
				}
			}
			else if (tmp.back() == 'F') {
				j = 1;
				state = false;
				tmp.pop_back();
				if (!result)
					continue;
				else {
					cout << result << "---";
					for (int i = 0; i < result; i++)
						board[numberOfLine].push_back(new cell(state));
					result = 0;
				}
			}
			else {
				//cout << tmp.back() << " ";
				result += ((int)tmp.back() - 48)*j;
				j *= 10;
				tmp.pop_back();
				
			}
		}
		numberOfLine++;
		cout << endl << endl;
	}
	cout << numberOfLine << endl;
	file.close();
	for (auto& rows : board) {
		for (auto& element : rows)
			cout << element.returnState() << " ";
		cout << endl;
	}
}
