#pragma once

#ifndef ROLE
#define ROLE

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include "Employee.h"
//#include "rapidxml/rapidxml.hpp"

using namespace std;
//using namespace rapidxml;

class Role {
protected:
	string name;//name
	int employeesNeeded[3];//stores the number of employees needed to staff the role, for all 3 shifts
	vector<int> trainedEmployees;
public:
	void addTrainedEmployee(int);
	Role(string, vector<Employee>, int);
	Role(const Role&);
	virtual ~Role();
};

#endif /*ROLE*/