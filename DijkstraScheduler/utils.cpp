#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "utils.h"

using namespace std;
using namespace rapidxml;

vector<string> getVectorFromFileName(string fileName) {
	vector<string> v = vector<string>();

	xml_node<>* node;
	//xml_attribute<>* attr;
	file<> xmlFile(fileName.c_str());
	xml_document<> d;
	d.parse<0>(xmlFile.data());

	node = d.first_node();
	if (node == 0)
		return v;

	for (node = node->first_node(); node; node = node->next_sibling()) {
		//cout << "one attr\n";
		v.push_back(string(node->value()));
	}

	return v;
}

map<string, int> getMapFromVector(vector<string> v) {
	map<string, int> m = map<string, int>();

	for (int i = 0; i < v.size(); i++)
		m.insert(pair<string, int>(v[i], i));

	return m;
}
