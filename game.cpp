/*********************************************************************
 * Program name: Group Project 1 - Group 8 - game.cpp
 * Authors: Sheila Babayan, Becky Chao, Elizabeth Donato, 
 * Devin Gendron, Ronald Walters
 * Date: 2/19/2018
 * Description: This is the implementation file for our Game class. It 
 * contains the game constructors and destructos, plus the utility 
 * functions needed to run the game.
 **********************************************************************/
 
#include "game.hpp"

//game constructor
Game::Game()
{}

void Game::startMenu()
{
    cout << "Predator Prey Menu" << endl;
    cout << "   1. Play Set Game" << endl;
    cout << "   2. Play Custom Game (EC)" << endl;
    cout << "Please choose an option: " << endl;
}

void Game::simulation()
{
    cout << "running game sim here" << endl;
/*	//dynamically allocate board space
	board = new char*[boardRows];
	for (int i = 0; i < boardRows; i++)
	{
		board[i] = new char[boardCols];
	}

	//creates board
	createBoard();

	for (int i = 0; i < steps; i++)
	{
		//moves critters
		moveFunc();

		//prints board
		printBoard();
	}

	//delete board
	for (int i = 0; i < 2; i++)
	{
		delete [] board[i];
	}
	delete [] board;
	board = NULL;
	*/
}

int Game::inputValidation()
{
    int choice = 0;
    int exitCount = 0;

        exitCount = 0;
        while (exitCount == 0)
        {

            int correctEntry = 0;
            int incorrectEntry = 0;
            std::string str = " ";

            //arrays to check user input
            char numEntry[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

            char letterEntry[] =
                    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                     'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                     'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                     'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

            char symEntry[] = {'`', '-','~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
                               '{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/', ' '};
            //removed: '\', '|', ';', ':', ''',

            //reads in string
            getline(std::cin, str);
            std::stringstream ss(str);

            //checks for empty entries
            bool badEntry = false;
            if (str.empty())
            {
                badEntry = true;
            }

            for (int t = 0; t < str.size(); t++)
            {
                //good entry
                for (int m = 0; m < 10; m++)
                {
                    if (str[t] == numEntry[m])
                    {
                        correctEntry ++;
                    }
                }
                //bad char entry
                for (int y = 0; y < 52; y++)
                {
                    if (str[t] == letterEntry[y])
                    {
                        incorrectEntry ++;
                    }
                }
                //bad symbol entry
                for (int n = 0; n < 24; n++)
                {
                    if (str[t] == symEntry[n])
                    {
                        incorrectEntry ++;
                    }
                }
            }
            if (badEntry == true)
            {
                std::cout << "Please enter an integer." << std::endl;
                exitCount = 0;
            }
            else if (correctEntry == str.size())
            {
                ss >> choice;
                exitCount = 1;
            }
            else if (incorrectEntry > 0)
            {
                std::cout << "Incorrect Entry." << std::endl;
                std::cout << "Please enter an integer: No characters, symbols, doubles, floats, or decimals." << std::endl;
                exitCount = 0;
            }
        }
    return choice;
}

//game destructor
Game::~Game()
{}