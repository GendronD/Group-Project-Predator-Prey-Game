/*********************************************************************
 * Program name: Group Project 1 - Group 8 - main.cpp
 * Authors: Sheila Babayan, Becky Chao, Elizabeth Donato, 
 * Devin Gendron, Ronald Walters
 * Date: 2/19/2018
 * Description: This is the Main function for Group 8's group project.
 **********************************************************************/
#include <iostream>
using std::cout;
using std::endl;

#include "Board.hpp"
#include "promptUser.hpp"
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"

#include <time.h>
#include <stdlib.h>

int main ()
{
    //random seed
    srand(time(NULL));  
    
    int choice = 0;
    int endGame = 1;
    Board *gameboard;
    int steps = 0;

    //extra credit message
    cout << "Extra credit is implemented on this project\n" << endl;
    
    //display starting menu options
    cout << "Predator Prey Menu" << endl;
    cout << "   1. Play Set Game" << endl;
    cout << "   2. Play Custom Game (EC)" << endl;
    cout << "Please choose an option: " << endl;
    
    //validate the user's selection
    choice = inputValidation();

    switch (choice)
    {
        case 1:     {//make a default gameboard;
                    gameboard = new Board;
                    steps = promptSteps();
                    }
                    break;
                    
        case 2:     {//make a custom gameboard
                    int rows = promptRows();        //Prompt user for number of rows
                    int cols = promptCols();        //Prompt user for number of columns
                    int ants = promptAnts();        //Prompt user for number of ants (controlled by rows/cols)
                    int dbugs = promptDoodles();     //Prompt user for number of doodlebugs (controlled by rows/cols)
                    steps = promptSteps();       //Prompt user for number of steps
                    //constructor with parameters for gameboard
                    gameboard = new Board(rows, cols, ants, dbugs);
                    }
                    break;
        default:    cout << "That's not a menu option. Please try again!\n" << endl;
                    //start over by recursively calling main
                    main();
    }
    
    gameboard->printBoard();

    /*
    //start game sim here
    do
    {}
    while (endGame != 1);
    */
    
    return 0;
}
