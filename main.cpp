/*********************************************************************
 * Program name: Group Project 1 - Group 8 - main.cpp
 * Authors: Sheila Babayan, Becky Chao, Elizabeth Donato, 
 * Devin Gendron, Ronald Walters
 * Date: 2/19/2018
 * Description: This is the Main function for Group 8's group project.
 **********************************************************************/

#include "inputValidation.hpp"
#include "Critter.hpp"
#include "Ant.hpp"
#include "DoodleBug.hpp"
#include "Board.hpp"
#include "PromptUser.hpp"

#include <iostream>
using std::cout;
using std::endl;

int main ()
{
    int choice = 0;
    cout << "Extra credit is implemented on this project" << endl;

    cout << "Predator Prey Menu" << endl;
    cout << "1. Play Set Game" << endl;
    cout << "2. Play Custom Game (EC)" << endl;
  
    choice = inputValidation();

switch (choice)
{
      case 1:   //default/normal game
                //Default constructor for game
                promptSteps();
                break;
      case 2:   //custom game
                promptRows();        //Prompt user for number of rows
                promptCols();        //Prompt user for number of columns
                promptAnts();        //Prompt user for number of ants (controlled by rows/cols)
                promptDoodles();     //Prompt user for number of doodlebugs (controlled by rows/cols)
                promptSteps();       //Prompt user for number of steps
                break;
      default:  cout << "That's not a menu option, something went wrong." << endl;
    }
  
    //start game sim here
    do
    {
        //runs simulation
        game.predatorPrey();	
    }
    while (endGame != 1);
    
    return 0;
}
