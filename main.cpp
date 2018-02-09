Menu
#include <iostream>
#include "inputValidation.h"
#include "Critter.h"
#include "Ant.h"
#include "DoodleBug.h"
#include "Board.h"
#include "PromptUser.h"

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
        Prompt user for number of steps
        break;
      Case 2 : //custom game
        Prompt user for number of rows
        Prompt user for number of columns
        Prompt user for number of ants (controlled by rows/cols)
        Prompt user for number of doodlebugs (controlled by rows/cols)
        Prompt user for number of steps
        Break;
    }
  //start game sim here
    Do
    {
      game.predatorPrey();	//runs simulation
    }while (endGame != 1);
    
    return 0;
}
