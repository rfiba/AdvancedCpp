#pragma once
#ifndef RLE_H
#define RLE_H


#include <iostream>
#include "cell.h"
#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <stack>
#include "board.h"

using namespace std;

unique_ptr<string[]> encodeRLE(vector<vector<cell>> &toEncode);
vector<vector<cell>> decodeRLEdirectFromFile(string nameOfFile);

#endif //RLE_H