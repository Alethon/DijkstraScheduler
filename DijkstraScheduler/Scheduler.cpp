#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "Scheduler.h"

using namespace std;
using namespace rapidxml;

Scheduler::Scheduler() {
	roleVector = vector<string>();
	roleMap = map<string, int>();

	xml_node<>* node;
	xml_attribute<>* attr;
	file<> xml(roleFile.c_str);
	xml_document<> d;
	d.parse<0>(xml.data());

	node = d.first_node("roles");
	if (node == 0)
		return;

	for (attr = node->first_attribute(); attr; attr = attr->next_attribute())
		roleVector.push_back(string(attr->value()));

	for (int i = 0; i < roleVector.size(); i++)
		roleMap.insert(pair<string, int>(roleVector[i], i));

	return;
}

Scheduler::Scheduler(const Scheduler& s) {
	roleVector = vector<string>();
	roleMap = map<string, int>();

	for (int i = 0; i < s.roleVector.size(); i++)
		roleVector.push_back(s.roleVector[i]);

	for (int i = 0; i < roleVector.size(); i++)
		roleMap.insert(pair<string, int>(roleVector[i], i));

	return;
}

Scheduler::~Scheduler() {
	roleVector.clear();
	roleMap.clear();
}

const map<string, int>& Scheduler::getRoleMap() { return roleMap; }
