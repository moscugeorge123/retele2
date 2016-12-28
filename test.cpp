#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <math.h>
#include <typeinfo>
#include <vector>

#include "class/mysql_connection.h"
#include "libs/json.hpp"

using namespace std;
using json = nlohmann::json;

int main()
{
	
	fstream f("game_structure.json");
	ofstream g("test.txt");
	char c;
	string s;
	// while(f>>c){
	// 	s.push_back(c);
	// }

	json j;
	f >> j;
	//j = json::parse(s);

	cout << j["1"]["B"][0] << endl;
	cout << j["1"]["B"][0+4] << endl;
	return 1;
}