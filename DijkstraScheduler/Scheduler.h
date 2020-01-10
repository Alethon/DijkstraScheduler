#pragma once

#ifndef SCHEDULER
#define SCHEDULER

#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Scheduler {
protected:
	const string roleFile = "roles.xml";
	vector<string> roleVector;
	map<string, int> roleMap;
public:
	const map<string, int>& getRoleMap();
	Scheduler();
	Scheduler(const Scheduler&);
	virtual ~Scheduler();
};


#endif /*SCHEDULER*/
