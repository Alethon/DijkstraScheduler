#include <stdio.h>
#include <iostream>
#include <string>

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "Role.h"
#include "Employee.h"

using namespace std;
using namespace rapidxml;

Role::Role(string fileName, vector<Employee> e, int num) {
	//initialize to defaults
	name = "";
	trainedEmployees = vector<int>();

	for (int i = 0; i < e.size(); i++) {
		if (e[i].hasRole(num))
			trainedEmployees.push_back(i);
	}

	for (int i = 0; i < 3; i++)
		employeesNeeded[i] = -1;

	//populate from xml file
	xml_node<>* node;
	xml_attribute<>* attr;
	file<> xml(fileName.c_str);
	xml_document<> d;
	d.parse<0>(xml.data());

	node = d.first_node("role");
	if (node == 0)
		return;
	
	attr = node->first_attribute();
	if (attr == 0)
		return;
	name = string(attr->value());

	for (int i = 0; i < 3; i++) {
		if (attr != 0)
			attr = attr->next_attribute();

		if (attr != 0)
			sscanf(node->value(), "%d", &(employeesNeeded[i]));
	}

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
