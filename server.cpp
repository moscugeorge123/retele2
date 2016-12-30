#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <string>
#include <fstream>

#include "libs/json.hpp" // JSON library

using namespace std;
using json = nlohmann::json;

#include "class/class.h" // Game Classes
/* Portul folosit */

int main(int argc, char* argv[])
{
  if(argc <= 0) return 1;
  /* Pornirea serverului pana la comanda bind */

  int PORT = atoi(argv[1]);
  Server* server = new Server(PORT);

  /* JSON file with Game Structure */
  ifstream json_file("game_structure.json");

  /* JSON Game Structure && read from file */
  json gameStructure;
  json_file >> gameStructure;

  /* Closing file */
  json_file.close();

  /* Vector with active games */
  vector<int> activeGames;

  /* Vector with games in wait */
  vector<game*> inWaitGames;

  /* Vector with players in game */
  vector<int> inGamePlayers;



  char v[2];
  v[1] = '\0';
  v[0] = '1';



  while(true)
  {
    int client;

    client = server->Accept();

    inGamePlayers.push_back(client);

    player *play = new player(gameStructure[v]);
    v[0]++;

    json send;

    send["no"] = play->getNo();
    send["color"] = play->getColor();

    string js = send.dump();
    char msg[2048];
    copy(js.begin(), js.end(), msg);
    msg[js.size()] = '\0';

    write(client, msg, js.size());

    if(inGamePlayers.size() >= 4) break;
  }

  return 0;
} 