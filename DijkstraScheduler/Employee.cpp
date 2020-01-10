#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "Employee.h"

using namespace std;
using namespace rapidxml;

Employee::Employee(string fileName, map<string, int> roleMap) {
	//initialize to defaults
	name = "";
	id = "";

	roles = vector<int>();

	//populate from xml file
	xml_node<>* node;
	xml_attribute<>* attr;
	file<> xml(fileName.c_str);
	xml_document<> d;
	d.parse<0>(xml.data());

	node = d.first_node("employee");
	if (node == 0)
		return;

	attr = node->first_attribute();
	if (attr == 0)
		return;
	name = string(attr->value());

	attr = attr->next_attribute();
	if (attr == 0)
		return;
	id = string(attr->value());

	for (attr = attr->next_attribute(); attr; attr = attr->next_attribute())
		roles.push_back(roleMap[string(attr->value())]);

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
