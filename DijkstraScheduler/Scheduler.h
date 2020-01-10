#pragma once

#ifndef SCHEDULER
#define SCHEDULER

#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "Employee.h"
#include "Role.h"

using namespace std;

vector<string> getVectorFromFileName(string);
map<string, int> getMapFromVector(vector<string>);

class Scheduler {
protected:
	const string roleFile = "roles.xml";
	const string idFile = "IDs.xml";
	vector<string> roleVector;
	vector<string> employeeIDs;
	vector<Role> roles;
	vector<Employee> employees;
	map<string, int> roleMap;
	map<string, int> idMap;
public:
	const map<string, int>& getRoleMap();
	const map<string, int>& getEmployeeMap();
	Scheduler();
	Scheduler(const Scheduler&);
	virtual ~Scheduler();
};


#endif /*SCHEDULER*/
