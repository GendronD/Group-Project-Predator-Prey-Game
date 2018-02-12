//Menu
#include <iostream>
#include "inputValidation.hpp"
#include "Critter.hpp"
#include "Ant.hpp"
#include "DoodleBug.hpp"
#include "Board.hpp"
#include "PromptUser.hpp"

Int main ()
{
  Int choice = 0;
  Std::cout << “Extra credit is implemented on this project” << std::endl;

  Std::cout << “Predator Prey Menu” << std::endl;
  Std::cout << “1. Play Set Game” << std::endl;
  Std::cout << “2. Play Custom Game (EC)” << std::endl;
  Choice = inputValidation();

    Switch (choice)
    {
      Case 1 : //set game
        Default constructor for game
        promptSteps();
        break;
      Case 2 : //custom game
        promptRows();        //Prompt user for number of rows
        promptCols();        //Prompt user for number of columns
        promptAnts();        //Prompt user for number of ants (controlled by rows/cols)
        promptDoodles();     //Prompt user for number of doodlebugs (controlled by rows/cols)
        promptSteps();       //Prompt user for number of steps
        Break;
    }
  //start game sim here
    Do
    {
      game.predatorPrey();	//runs simulation
    }while (endGame != 1);
    
    return 0;
}
