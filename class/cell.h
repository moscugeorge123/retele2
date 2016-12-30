class cell
{
private:
	int x;
	int y;
	int type; /* 0 => NULL_cell, 1 => path_cell, 2 => B_cell, 3 => start_cell, 4 => finish_cell */
	cell *nextCell[4];
public:
	cell(int x, int y)
	{
		if(x < 0 || y < 0) fprintf(stderr, "Nu s-a putut crea celula!");

		this->x = x;
		this->y = y;
		this->type = 0;
	}
	~cell();
	
};