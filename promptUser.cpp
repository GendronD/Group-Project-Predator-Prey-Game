/*********************************************************************
 * Program name: Group Project 1 - Group 8 - promptUser.cpp
 * Authors: Sheila Babayan, Becky Chao, Elizabeth Donato, 
 * Devin Gendron, Ronald Walters
 * Date: 2/19/2018
 * Description: This is the implementation file for our promptUser functions,
 * which are used to establish the parameters of the game (rows, columns,
 * number of bugs, steps in gameplay). It also performs input validation.
*********************************************************************/

#include "promptUser.hpp"

/*********************************************************************
function inputValidation()
- checks user input
- returns only integers
*********************************************************************/
int inputValidation()
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

/*********************************************************************
function mainMenu()
- prompts user for menu choice
- checks user input using input validation
- returns only integers (1-3)
*********************************************************************/
int mainMenu()
{
    int menuChoice = 0;
    int exitCount = 0;

    //menu
    //std::cout << "Menu choice: " << std::endl;

    do
    {
        exitCount = 0;			//sets to continue while loop in do-while
        while (exitCount == 0)
        {
            int correctEntry = 0;
            int incorrectEntry = 0;
            std::string str = " ";
            int inputLength = str.size();

            //arrays to check string
            char numEntry[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

            char letterEntry[] =
                    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                     'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                     'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                     'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

            char symEntry[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
                               '{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/', ' ', '-', '_', '+', '='};
            //removed: '\', '|', ';', ':', ''',

            //reads in user input
            getline(std::cin, str);
            std::stringstream ss(str);

            //checks for empty strings
            bool badEntry = false;
            if (str.empty())
            {
                badEntry = true;
            }

            //checks for proper ints or incorrect entries
            for (int t = 0; t < str.size(); t++)
            {
                for (int m = 0; m < 10; m++)
                {
                    if (str[t] == numEntry[m])
                    {
                        correctEntry ++;
                    }
                }
                for (int y = 0; y < 52; y++)
                {
                    if (str[t] == letterEntry[y])
                    {
                        incorrectEntry ++;
                    }
                }
                for (int n = 0; n < 28; n++)
                {
                    if (str[t] == symEntry[n])
                    {
                        incorrectEntry ++;
                    }
                }
            }
            if (badEntry == true)
            {
                std::cout << "Please enter at least one integer." << std::endl;
                exitCount = 0;
            }
            else if (correctEntry == str.size())
            {
                ss >> menuChoice;
                //std::cout << "Correct Input." << std::endl;
                exitCount++;
            }
            else if (incorrectEntry > 0)
            {
                std::cout << "Incorrect Entry." << std::endl;
                std::cout << "Please enter an integer: No characters, symbols, doubles, floats, or decimals." << std::endl;
                exitCount = 0;
            }
        }

        if (menuChoice >= 1 && menuChoice <= 3)
        {
            exitCount = 0;
        }
        else
        {
            exitCount = 1;
            std::cout << "Please use proper range." << std::endl;
        }

    } while(exitCount == 1);

    return menuChoice;
}

/*********************************************************************
function promptRows()
- prompts user for number of rows for gameboard
- checks user input using input validation
- returns only integers
*********************************************************************/
int promptRows()
{
    int rows = 0;
    int exitCount = 0;

    //menu
    std::cout << "Please enter the number of rows between 10 and 100." << std::endl;

    do
    {
        exitCount = 0;			//sets to continue while loop in do-while
        while (exitCount == 0)
        {
            int correctEntry = 0;
            int incorrectEntry = 0;
            std::string str = " ";
            int inputLength = str.size();

            //arrays to check string
            char numEntry[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

            char letterEntry[] =
                    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                     'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                     'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                     'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

            char symEntry[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
                               '{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/', ' ', '-', '_', '+', '='};
            //removed: '\', '|', ';', ':', ''',

            //reads in user input
            getline(std::cin, str);
            std::stringstream ss(str);

            //checks for empty strings
            bool badEntry = false;
            if (str.empty())
            {
                badEntry = true;
            }

            //checks for proper ints or incorrect entries
            for (int t = 0; t < str.size(); t++)
            {
                for (int m = 0; m < 10; m++)
                {
                    if (str[t] == numEntry[m])
                    {
                        correctEntry ++;
                    }
                }
                for (int y = 0; y < 52; y++)
                {
                    if (str[t] == letterEntry[y])
                    {
                        incorrectEntry ++;
                    }
                }
                for (int n = 0; n < 28; n++)
                {
                    if (str[t] == symEntry[n])
                    {
                        incorrectEntry ++;
                    }
                }
            }
            if (badEntry == true)
            {
                std::cout << "Please enter at least one integer." << std::endl;
                exitCount = 0;
            }
            else if (correctEntry == str.size())
            {
                ss >> rows;
                //std::cout << "Correct Input." << std::endl;
                exitCount++;
            }
            else if (incorrectEntry > 0)
            {
                std::cout << "Incorrect Entry." << std::endl;
                std::cout << "Please enter an integer: No characters, symbols, doubles, floats, or decimals." << std::endl;
                exitCount = 0;
            }
        }

        if (rows >= 10 && rows <= 100)
        {
            exitCount = 0;
        }
        else
        {
            exitCount = 1;
            std::cout << "Please use proper range." << std::endl;
        }

    } while(exitCount == 1);

    return rows;
}
/*********************************************************************
function promptCols()
- prompts user for number of columns for gameboard
- checks user input using input validation
- returns only integers
*********************************************************************/
int promptCols()
{
    int cols = 0;
    int exitCount = 0;

    //menu
    std::cout << "Please enter the number of columns between 10 and 100." << std::endl;

    do
    {
        exitCount = 0;			//sets to continue while loop in do-while
        while (exitCount == 0)
        {
            int correctEntry = 0;
            int incorrectEntry = 0;
            std::string str = " ";
            int inputLength = str.size();

            //arrays to check string
            char numEntry[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

            char letterEntry[] =
                    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                     'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                     'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                     'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

            char symEntry[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
                               '{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/', ' ', '-', '_', '+', '='};
            //removed: '\', '|', ';', ':', ''',

            //reads in user input
            getline(std::cin, str);
            std::stringstream ss(str);

            //checks for empty strings
            bool badEntry = false;
            if (str.empty())
            {
                badEntry = true;
            }

            //checks for proper ints or incorrect entries
            for (int t = 0; t < str.size(); t++)
            {
                for (int m = 0; m < 10; m++)
                {
                    if (str[t] == numEntry[m])
                    {
                        correctEntry ++;
                    }
                }
                for (int y = 0; y < 52; y++)
                {
                    if (str[t] == letterEntry[y])
                    {
                        incorrectEntry ++;
                    }
                }
                for (int n = 0; n < 28; n++)
                {
                    if (str[t] == symEntry[n])
                    {
                        incorrectEntry ++;
                    }
                }
            }
            if (badEntry == true)
            {
                std::cout << "Please enter at least one integer." << std::endl;
                exitCount = 0;
            }
            else if (correctEntry == str.size())
            {
                ss >> cols;
                //std::cout << "Correct Input." << std::endl;
                exitCount++;
            }
            else if (incorrectEntry > 0)
            {
                std::cout << "Incorrect Entry." << std::endl;
                std::cout << "Please enter an integer: No characters, symbols, doubles, floats, or decimals." << std::endl;
                exitCount = 0;
            }
        }

        if (cols >= 10 && cols <= 100)
        {
            exitCount = 0;
        }
        else
        {
            exitCount = 1;
            std::cout << "Please use proper range." << std::endl;
        }

    } while(exitCount == 1);

    return cols;
}

/*********************************************************************
function promptAnts()
- prompts user for number of ants for gameboard
- checks user input using input validation
- returns only integers
*********************************************************************/
int promptAnts()
{
    int ants = 0;
    int exitCount = 0;

    //menu
    std::cout << "Please enter the number of ants to fit your custom board." << std::endl;

    do
    {
        exitCount = 0;			//sets to continue while loop in do-while
        while (exitCount == 0)
        {
            int correctEntry = 0;
            int incorrectEntry = 0;
            std::string str = " ";
            int inputLength = str.size();

            //arrays to check string
            char numEntry[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

            char letterEntry[] =
                    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                     'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                     'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                     'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

            char symEntry[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
                               '{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/', ' ', '-', '_', '+', '='};
            //removed: '\', '|', ';', ':', ''',

            //reads in user input
            getline(std::cin, str);
            std::stringstream ss(str);

            //checks for empty strings
            bool badEntry = false;
            if (str.empty())
            {
                badEntry = true;
            }

            //checks for proper ints or incorrect entries
            for (int t = 0; t < str.size(); t++)
            {
                for (int m = 0; m < 10; m++)
                {
                    if (str[t] == numEntry[m])
                    {
                        correctEntry ++;
                    }
                }
                for (int y = 0; y < 52; y++)
                {
                    if (str[t] == letterEntry[y])
                    {
                        incorrectEntry ++;
                    }
                }
                for (int n = 0; n < 28; n++)
                {
                    if (str[t] == symEntry[n])
                    {
                        incorrectEntry ++;
                    }
                }
            }
            if (badEntry == true)
            {
                std::cout << "Please enter at least one integer." << std::endl;
                exitCount = 0;
            }
            else if (correctEntry == str.size())
            {
                ss >> ants;
                //std::cout << "Correct Input." << std::endl;
                exitCount++;
            }
            else if (incorrectEntry > 0)
            {
                std::cout << "Incorrect Entry." << std::endl;
                std::cout << "Please enter an integer: No characters, symbols, doubles, floats, or decimals." << std::endl;
                exitCount = 0;
            }
        }

        if (ants >= 1 && ants <= 5000)
        {
            exitCount = 0;
        }
        else
        {
            exitCount = 1;
            std::cout << "Please use proper range." << std::endl;
        }

    } while(exitCount == 1);

    return ants;
}

/*********************************************************************
function promptDoodles()
- prompts user for number of doodlebugs for gameboard
- checks user input using input validation
- returns only integers
*********************************************************************/
int promptDoodles()
{
    int doodlebugs = 0;
    int exitCount = 0;

    //menu
    std::cout << "Please enter the number of doodlebugs to fit the area of your custom board." << std::endl;

    do
    {
        exitCount = 0;			//sets to continue while loop in do-while
        while (exitCount == 0)
        {
            int correctEntry = 0;
            int incorrectEntry = 0;
            std::string str = " ";
            int inputLength = str.size();

            //arrays to check string
            char numEntry[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

            char letterEntry[] =
                    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                     'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                     'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                     'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

            char symEntry[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
                               '{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/', ' ', '-', '_', '+', '='};
            //removed: '\', '|', ';', ':', ''',

            //reads in user input
            getline(std::cin, str);
            std::stringstream ss(str);

            //checks for empty strings
            bool badEntry = false;
            if (str.empty())
            {
                badEntry = true;
            }

            //checks for proper ints or incorrect entries
            for (int t = 0; t < str.size(); t++)
            {
                for (int m = 0; m < 10; m++)
                {
                    if (str[t] == numEntry[m])
                    {
                        correctEntry ++;
                    }
                }
                for (int y = 0; y < 52; y++)
                {
                    if (str[t] == letterEntry[y])
                    {
                        incorrectEntry ++;
                    }
                }
                for (int n = 0; n < 28; n++)
                {
                    if (str[t] == symEntry[n])
                    {
                        incorrectEntry ++;
                    }
                }
            }
            if (badEntry == true)
            {
                std::cout << "Please enter at least one integer." << std::endl;
                exitCount = 0;
            }
            else if (correctEntry == str.size())
            {
                ss >> doodlebugs;
                //std::cout << "Correct Input." << std::endl;
                exitCount++;
            }
            else if (incorrectEntry > 0)
            {
                std::cout << "Incorrect Entry." << std::endl;
                std::cout << "Please enter an integer: No characters, symbols, doubles, floats, or decimals." << std::endl;
                exitCount = 0;
            }
        }

        if (doodlebugs >= 1 && doodlebugs <= 2500)
        {
            exitCount = 0;
        }
        else
        {
            exitCount = 1;
            std::cout << "Please use proper range." << std::endl;
        }

    } while(exitCount == 1);

    return doodlebugs;
}

/*********************************************************************
function promptSteps()
- prompts user for number of steps for the game
- checks user input using input validation
- returns only integers
*********************************************************************/
int promptSteps()
{
    int steps = 0;
    int exitCount = 0;

    //menu
    std::cout << "Please enter the number of steps between 1 and 15000." << std::endl;

    do
    {
        exitCount = 0;			//sets to continue while loop in do-while
        while (exitCount == 0)
        {
            int correctEntry = 0;
            int incorrectEntry = 0;
            std::string str = " ";
            int inputLength = str.size();

            //arrays to check string
            char numEntry[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

            char letterEntry[] =
                    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                     'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                     'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                     'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

            char symEntry[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
                               '{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/', ' ', '-', '_', '+', '='};
            //removed: '\', '|', ';', ':', ''',

            //reads in user input
            getline(std::cin, str);
            std::stringstream ss(str);

            //checks for empty strings
            bool badEntry = false;
            if (str.empty())
            {
                badEntry = true;
            }

            //checks for proper ints or incorrect entries
            for (int t = 0; t < str.size(); t++)
            {
                for (int m = 0; m < 10; m++)
                {
                    if (str[t] == numEntry[m])
                    {
                        correctEntry ++;
                    }
                }
                for (int y = 0; y < 52; y++)
                {
                    if (str[t] == letterEntry[y])
                    {
                        incorrectEntry ++;
                    }
                }
                for (int n = 0; n < 28; n++)
                {
                    if (str[t] == symEntry[n])
                    {
                        incorrectEntry ++;
                    }
                }
            }
            if (badEntry == true)
            {
                std::cout << "Please enter at least one integer." << std::endl;
                exitCount = 0;
            }
            else if (correctEntry == str.size())
            {
                ss >> steps;
                //std::cout << "Correct Input." << std::endl;
                exitCount++;
            }
            else if (incorrectEntry > 0)
            {
                std::cout << "Incorrect Entry." << std::endl;
                std::cout << "Please enter an integer: No characters, symbols, doubles, floats, or decimals." << std::endl;
                exitCount = 0;
            }
        }

        if (steps >= 1 && steps <= 15000)
        {
            exitCount = 0;
        }
        else
        {
            exitCount = 1;
            std::cout << "Please use proper range." << std::endl;
        }

    } while(exitCount == 1);

    return steps;
}
