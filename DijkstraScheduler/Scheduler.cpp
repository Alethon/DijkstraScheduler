#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "Scheduler.h"
#include "Employee.h"
#include "Role.h"

using namespace std;
using namespace rapidxml;

vector<string> getVectorFromFileName(string fileName) {
	vector<string> v = vector<string>();

	xml_node<>* node;
	xml_attribute<>* attr;
	file<> xml(fileName.c_str);
	xml_document<> d;
	d.parse<0>(xml.data());

	node = d.first_node();
	if (node == 0)
		return v;

	for (attr = node->first_attribute(); attr; attr = attr->next_attribute())
		v.push_back(string(attr->value()));

	return v;
}

map<string, int> getMapFromVector(vector<string> v) {
	map<string, int> m = map<string, int>();

	for (int i = 0; i < v.size(); i++)
		m.insert(pair<string, int>(v[i], i));

	return m;
}

Scheduler::Scheduler() {
	roleVector = getVectorFromFileName(roleFile);
	employeeIDs = getVectorFromFileName(idFile);
	roleMap = getMapFromVector(roleVector);
	idMap = getMapFromVector(employeeIDs);

	employees = vector<Employee>();
	for (int i = 0; i < employeeIDs.size(); i++)
		employees.push_back(Employee(employeeIDs[i] + ".xml", roleMap));//what if the employee knows a removed role?

	roles = vector<Role>();
	for (int i = 0; i < roleVector.size(); i++)
		roles.push_back(Role(roleVector[i] + ".xml", employees, i));

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
