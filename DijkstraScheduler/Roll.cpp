#include <stdio.h>
#include <iostream>
#include <string>

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "Roll.h"

using namespace std;
using namespace rapidxml;

Roll::Roll(string fileName) {
	//initialize to defaults
	name = "";

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

Roll::Roll(const Roll& roll) {
	name = roll.name;
	for (int i = 0; i < 3; i++)
		employeesNeeded[i] = roll.employeesNeeded[i];
	return;
}

Roll::~Roll() { return; }
