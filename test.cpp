#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <math.h>
#include <typeinfo>
#include <vector>

#include "libs/json.hpp"

using namespace std;
using json = nlohmann::json;

#include "class/player.h"


int main()
{
	
	ifstream f("game_structure.json");

	json j;

	f >> j;

	player *player1 = new player(j["1"]);


	return 1;
}