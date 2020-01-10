#pragma once

#ifndef EMPLOYEE
#define EMPLOYEE

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Employee {
protected:
	string name;
	string id;
	vector<int> roles;
public:
	bool hasRole(int);
	Employee(string, map<string, int>);
	Employee(const Employee&);
	virtual ~Employee();
};

#endif /*EMPLOYEE*/
