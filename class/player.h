class player
{
private:
	vector<vector<int>> path;
	vector<int> finish;
	vector<int> B;
	vector<int> start;
	string no;
	string color;
	vector<int> dot_position;
	int path_size;

public:

	bool moveDot(int dot, int moves)
	{
		if(this->dot_position[dot] + moves > this->path_size - 1) 
			return false;

		this->dot_position[dot] += moves;
		return true;
	}

	vector<vector<int>> getPath()
	{
		return this->path;
	}

	vector<int> getFinish()
	{
		return this->finish;
	}

	vector<int> getB()
	{
		return this->B;
	}

	vector<int> getStart()
	{
		return this->start;
	}

	vector<int> getDotPosition()
	{
		return this->dot_position;
	}

	string getNo()
	{
		return this->no;
	}

	int getPathSize()
	{
		return this->path_size;
	}

	string getColor()
	{
		return this->color;
	}

	player(json data){
		if(data != NULL)
		{
			this->path = data["path"].get<vector<vector<int>>>();
			this->finish = data["finish"].get<vector<int>>();
			this->B = data["B"].get<vector<int>>();
			this->start = data["start"].get<vector<int>>();
			this->no = data["no"].get<string>();
			this->dot_position = {-1, -1, -1, -1};
			this->path_size = this->path.size() + this->finish.size();

			if(this->no == "B1") this->color = "orange";
			if(this->no == "B2") this->color = "blue";
			if(this->no == "B3") this->color = "red";
			if(this->no == "B4") this->color = "green";
		}
	}
	~player();
	
};