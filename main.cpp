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
    Board *gameboard;
    int steps = 0;
    int rows = 0;
    int cols = 0;
    int ants = 0;
    int dbugs = 0;

    //extra credit message
    cout << "Extra credit is implemented on this project\n" << endl;

    //display starting menu options
    cout << "Predator Prey Menu" << endl;
    cout << "   1. Play Set Game" << endl;
    cout << "   2. Play Custom Game (EC)" << endl;
    cout << "   3. Quit Game." << endl;
    cout << "Please choose an option: " << endl;

    //validate the user's selection
    choice = mainMenu();

    switch (choice)
    {
        case 1:  //make a default gameboard;
            gameboard = new Board;
            steps = promptSteps();
            break;

        case 2:  //make a custom gameboard
            rows = promptRows();        //Prompt user for number of rows
            cols = promptCols();        //Prompt user for number of columns
            ants = promptAnts();        //Prompt user for number of ants (controlled by rows/cols)
            dbugs = promptDoodles();     //Prompt user for number of doodlebugs (controlled by rows/cols)
            steps = promptSteps();       //Prompt user for number of steps
            //constructor with parameters for gameboard
            gameboard = new Board(rows, cols, ants, dbugs);

            cout << "Initial gameboard. Doodlebugs, start your engines." << endl;
            gameboard->printBoard();

            //runs simulation
            gameboard->simulation(steps);

            std::cout<< "game ended!" << std::endl;
            break;

        case 3 : //quit game
            cout << "Game Quit" << endl;
            break;

        default:    cout << "That's not a menu option. Please try again!\n" << endl;
            //start over by recursively calling main
            main();
    }

    return 0;
}
