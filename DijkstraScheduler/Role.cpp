#include <stdio.h>
#include <iostream>
#include <string>

#include "utils.h"
#include "Role.h"
#include "Employee.h"

using namespace std;

Role::Role(string fileName, vector<Employee> e, int num) {
	vector<string> readData = getVectorFromFileName(fileName);

	name = readData[0];

	for (int i = 1; i < 4; i++)
		sscanf_s(readData[i].c_str(), "%d", &(employeesNeeded[i - 1]));

	for (int i = 0; i < e.size(); i++) {
		if (e[i].hasRole(num))
			trainedEmployees.push_back(i);
	}

	readData.clear();

	return;
}

Role::Role(const Role& role) {
	name = role.name;
	for (int i = 0; i < 3; i++)
		employeesNeeded[i] = role.employeesNeeded[i];
	trainedEmployees = vector<int>();
	for (int i = 0; i < role.trainedEmployees.size(); i++)
		trainedEmployees.push_back(role.trainedEmployees[i]);
	return;
}

Role::~Role() {
	trainedEmployees.clear();
}

void Role::addTrainedEmployee(int e) {
	trainedEmployees.push_back(e);
	return;
}

void Role::print() {
	cout << endl;
	cout << "Role: " << name << endl;
	cout << "day:\t" << employeesNeeded[0] << endl;
	cout << "evening:\t" << employeesNeeded[1] << endl;
	cout << "night:\t" << employeesNeeded[2] << endl;
	cout << "trained:";
	for (auto i = trainedEmployees.begin(); i != trainedEmployees.end(); ++i)
		cout << " " << *i;
	cout << endl;
	cout << endl;
}
