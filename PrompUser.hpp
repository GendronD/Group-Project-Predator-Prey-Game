#ifndef PROMPTUSER_HPP
#define PROMPTUSER_HPP

#include <iostream>
#include <string>
#include <sstream>

int promptRows();        //Prompt user for number of rows
int promptCols();        //Prompt user for number of columns
int promptAnts();        //Prompt user for number of ants (controlled by rows/cols)
int promptDoodles();     //Prompt user for number of doodlebugs (controlled by rows/cols)
int promptSteps();       //Prompt user for number of steps

#endif //PROMPTUSER
