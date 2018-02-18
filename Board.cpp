/*********************************************************************
 * Program name: Group Project 1 - Group 8 - Board.cpp
 * Authors: Sheila Babayan, Becky Chao, Elizabeth Donato, 
 * Devin Gendron, Ronald Walters
 * Date: 2/19/2018
 * Description: This is the implementation file for our Board class. It 
 * contains the functions for our Board object.
 **********************************************************************/
#include "Board.hpp"
#include "Menu.hpp"
#include "UserInput.hpp"

//default constructor
Board::Board()
{
    //Set standard size of board
    rows = 20;
    cols = 20;

    //Create the board itself
    board = new Critter**[rows];
    for (int x = 0; x < rows; x++)
    {
        board[x] = new Critter*[cols];
    }

    //Fill board with Critter objects
    for (int rw = 0; rw < rows; rw++)
    {
        for (int cl = 0; cl < cols; cl++)
        {
            board[rw][cl] = new Critter();
        }
    }

    //Place ants randomly on board
    for (int z = 0; z < 100; z++)
    {
        int randRowA = rand() % rows;
        int randColA = rand() % cols;
        board[randRowA][randColA] = new Ant(randRowA, randColA, 0);
    }

    //Place doodlebugs randomly on board
    for (int d = 0; d < 5; d++)
    {
        int randRowD = rand() % rows;
        int randColD = rand() % cols;
        board[randRowD][randColD] = new Doodlebug(randRowD, randColD, 0, 0);
    }
}

//overloaded for custom rows/columns
Board::Board(int r, int c, int a, int d)
{
    rows = r;
    cols = c;
    ants = a;
    dbugs = d;

    board = new Critter**[rows];
    for (int x = 0; x < rows; x++)
    {
        board[x] = new Critter*[cols];
    }

    //Fill board with Critter objects
    for (int rw = 0; rw < rows; rw++)
    {
        for (int cl = 0; cl < cols; cl++)
        {
            board[rw][cl] = new Critter();
        }
    }

    //Place ants randomly on board
    for (int z = 0; z < ants; z++)
    {
        int randRowA = rand() % rows;
        int randColA = rand() % cols;
        board[randRowA][randColA] = new Ant(randRowA, randColA, 0);
    }

    //Place doodlebugs randomly on board
    for (int dbs = 0; dbs < dbugs; dbs++)
    {
        int randRowD = rand() % rows;
        int randColD = rand() % cols;
        board[randRowD][randColD] = new Doodlebug(randRowD, randColD, 0, 0);
    }
}

//destructor
Board::~Board()
{

    for (int del = 0; del < rows; del++)
    {
        for (int pt = 0; pt < cols; pt++)
        {
            delete board[del][pt];
        }
        delete[] board[del];
    }
    delete [] board;
    board = NULL;
}

//print board function
void Board::printBoard()
{
    //system("clear");	//this creates a better flipbook effect for me

    //std::cout << "\033[2J\033[1;1H";	//this does a poor job (at least on my mac)

    //prints board
    for (int r = 0; r < rows+2; r++)
    {
        for (int c = 0; c < cols+2; c++)
        {
            if (r == 0 || r == rows+1)
            {
                cout << '-';
            }
            else if (c == 0 || c == cols+1)
            {
                cout << '|';
            }
            else
            {
                cout << board[r-1][c-1]->getSymbol();
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

void Board::simulation(int s)
{
    int steps = s;
    int end = 0;
    
    Menu newMenu;
    UserInput newInput;

    //start game sim here
    do
    {
        for (int i = 0; i < steps; i++)
        {
            std::cout << "Test Doodelbugs" << std::endl;
            //loop through for doodlebugs
            for (int rw = 0; rw < rows; rw++)
            {
                for (int cl = 0; cl < cols; cl++)
                {
                    if(board[rw][cl]->getSymbol() == 'X')
                    {
                        board[rw][cl]->move(board, rows, cols);
                        board[rw][cl]->breed(board, rows, cols);
                        board[rw][cl]->starve(board);
                    }
                }
            }
            std::cout << "Test ants" << std::endl;
            //loop through for ants
            for (int rw = 0; rw < rows; rw++)
            {
                for (int cl = 0; cl < cols; cl++)
                {
                    if(board[rw][cl]->getSymbol() == 'O')
                    {
                        board[rw][cl]->move(board, rows, cols);
                        board[rw][cl]->breed(board, rows, cols);
                    }
                }
            }
            printBoard();
        }
        
	mChoice = newMenu.get_choice();

        switch(mChoice)
        {
            case 1 : //add more steps
                steps = newInput.prompt_steps();
                end = 0;
                break;
            case 2 : //quit game
                end = 1;
                break;
        }

    } while (end == 0);
}