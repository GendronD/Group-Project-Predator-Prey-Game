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

#include "game.hpp"
#include "promptUser.hpp"
//#include "critter.hpp"
//#include "ant.hpp"
//#include "doodleBug.hpp"
//#include "board.hpp"

int main ()
{
    srand(time(NULL));  //random seed
    
    int choice = 0;
    int endGame = 1;
    cout << "Extra credit is implemented on this project" << endl;
    
    //create a Game object
    Game g1;
    
    //call the Game's starting menu options
    g1.startMenu();
    
    //validate the user's selection
    choice = g1.inputValidation();

    switch (choice)
    {
        case 1:     //Default constructor for gameboard
                    //set the gameboard's #rows, cols
                    //Prompt user for number of steps
                    promptSteps();
                    break;
        case 2:     promptRows();        //Prompt user for number of rows
                    promptCols();        //Prompt user for number of columns
                    promptAnts();        //Prompt user for number of ants (controlled by rows/cols)
                    promptDoodles();     //Prompt user for number of doodlebugs (controlled by rows/cols)
                    promptSteps();       //Prompt user for number of steps
                    //constructor with parameters for gameboard
                    break;
        default:    cout << "That's not a menu option. Please try again!\n" << endl;
                    //start over by recursively calling main
                    main();
    }
    
    
    //this is for testing, we can delete it later. Not sure how endGame works below.
    if ((choice == 1) || (choice == 2))
    {
        g1.simulation();
    }
    /*
    //start game sim here
    do
    {
        //runs simulation
        game.predatorPrey();
        endGame = 1;
    }
    while (endGame != 1);
    */
    
    return 0;
}
