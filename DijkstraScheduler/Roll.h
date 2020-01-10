#pragma once

#ifndef ROLL
#define ROLL

#include <stdio.h>
#include <iostream>
#include <string>
//#include <array>
//#include "rapidxml/rapidxml.hpp"

using namespace std;
//using namespace rapidxml;

class Roll {
protected:
	string name;//name
	int employeesNeeded[3];//stores the number of employees needed to staff the roll, for all 3 shifts
public:
	Roll(string);
	Roll(const Roll&);
	virtual ~Roll();
};

#endif /*ROLL*/