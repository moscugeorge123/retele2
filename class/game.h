class game
{
private:
	vector<player*> clients;
	int players;
public:

	bool setPlayer(json Player)
	{
		this->clients[this->players] = new player(Player);
	}

	game(json firstPlayer)
	{
		this->players = 0;
		this->setPlayer(firstPlayer);
	}

	game()
	{
		this->players = 0;
	};
	~game();
	
};