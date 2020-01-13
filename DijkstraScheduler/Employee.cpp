#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "utils.h"
#include "Employee.h"

using namespace std;

Employee::Employee(string fileName, map<string, int> roleMap) {
	vector<string> readData = getVectorFromFileName(fileName);

	name = readData[0];
	id = readData[1];

	for (int i = 2; i < readData.size(); i++)
		roles.push_back(roleMap[readData[i]]);

	readData.clear();

	return;
}

Employee::Employee(const Employee& e) {
	name = e.name;
	id = e.id;
	roles = vector<int>();
	for (int i = 0; i < e.roles.size(); ++i)
		roles.push_back(e.roles[i]);
	return;
}

Employee::~Employee() {
	roles.clear();
}

bool Employee::hasRole(int role) {
	return find(roles.begin(), roles.end(), role) != roles.end();
}
