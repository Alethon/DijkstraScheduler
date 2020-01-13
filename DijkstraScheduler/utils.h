#pragma once

#ifndef UTILS
#define UTILS

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> getVectorFromFileName(string);
map<string, int> getMapFromVector(vector<string>);

#endif /*UTILS*/