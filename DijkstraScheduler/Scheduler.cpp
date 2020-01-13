#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "utils.h"
#include "Scheduler.h"
#include "Employee.h"
#include "Role.h"

using namespace std;

Scheduler::Scheduler() {
	roleVector = getVectorFromFileName(roleFile);
	employeeIDs = getVectorFromFileName(idFile);
	roleMap = getMapFromVector(roleVector);
	idMap = getMapFromVector(employeeIDs);

	employees = vector<Employee>();
	for (int i = 0; i < employeeIDs.size(); i++)
		employees.push_back(Employee("employees\\" + employeeIDs[i] + ".xml", roleMap));//what if the employee knows a removed role?

	roles = vector<Role>();
	for (int i = 0; i < roleVector.size(); i++) {
		roles.push_back(Role("roles\\" + roleVector[i] + ".xml", employees, i));
	}

	return;
}

Scheduler::Scheduler(const Scheduler& s) {
	roleVector = vector<string>();
	roleMap = map<string, int>();
	employees = vector<Employee>();
	roles = vector<Role>();

	for (int i = 0; i < s.roleVector.size(); i++)
		roleVector.push_back(s.roleVector[i]);

	for (int i = 0; i < roleVector.size(); i++)
		roleMap.insert(pair<string, int>(s.roleVector[i], i));

	for (int i = 0; i < employeeIDs.size(); i++)
		employees.push_back(s.employees[i]);//what if the employee knows a removed role?

	for (int i = 0; i < roleVector.size(); i++)
		roles.push_back(s.roles[i]);

	return;
}

Scheduler::~Scheduler() {
	roleVector.clear();
	roleMap.clear();
}

const map<string, int>& Scheduler::getRoleMap() { return roleMap; }

void Scheduler::printRoles() {
	for (Role role : roles)
		role.print();
}

int main() {
	Scheduler* s = new Scheduler();
	s->printRoles();
	return 0;
}
