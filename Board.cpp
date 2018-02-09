//default constructor
Board::Board()
{
  
}

//overloaded for custom rows/columns
Board::Board(int r, int c) : rows(r), cols(c)
{
  
}

//destructor
Board::~Board()
{
  
}

//setrows
void Board::setRows(int r)
{
  boardRows = r;
}

//setcols
void Board::setColumns(int c)
{
  boardCols = c;
}

//create board function
void Board::createBoard()
{
	//creates board
	for (int i = 0; i < boardCols; i++)
	{
		board[0][i] = '-';	//top row
	}

	for (int i = 0; i < boardRows; i++)
	{
		for (int j = 0; j < boardCols; j++)
		{
			if(j == 0)
			{
				board[i][j] = '|';	//left wall
			}
			else
			{
				board[i][j] = ' ';
			}
			if(j == boardCols - 1)
			{
				board[i][j] = '|';		//right side wall
			}
		}
	}
	for (int i = 0; i < boardCols; i++)
	{
		board[boardRows - 1][i] = '-';	//bottom row
	}
}

//print board function
void Board::printBoard()
{
	//system("clear");	//this creates a better flipbook effect for me

	std::cout << "\033[2J\033[1;1H";	//this does a poor job (at least on my mac) 

	//prints board
	for(int i = 0; i < boardRows; i++)
	{
    		for(int j = 0; j < boardCols; j++)
    		{
			if (i == 0 || i == boardCols - 1) 
			{
				 board[i][j] = '-';
			}
	       		 else if(j == 0 || j == boardCols -1) 
		    	{
		        		board[i][j] = '|';
	       		}
			else 
			{
			board[i][j];  
			}
			std::cout << board[i][j];
    		}
    		std::cout << std::endl;
	}
}

