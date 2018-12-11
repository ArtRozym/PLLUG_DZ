#include <QCoreApplication>
#include <iostream>
#include <string>
#include <time.h>

int main()
{
    std::cout << "Enter Rock, Scissors or Paper: \n";
    std::string computer = "", player ="";
    std::cin >> player;

    int random=0;
    srand(time(NULL));
    random = rand() % 3 + 1;

    switch (random) {
    case 1:
        computer = "Rock";
        break;
    case 2:
        computer = "Scissors";
        break;
    case 3:
        computer = "Paper";
        break;
    default:
        break;
    }

    if(((player == "Rock")&&(computer == "Scissors"))||((player == "Scissors")&&(computer == "Paper"))||((player == "Paper")&&(computer == "Rock")))
    {
        std::cout<<"\nplayer = " << player;
        std::cout<<"\ncomputer = " << computer;
        std::cout<<"\nYou win!\n\n";
    }
    else if(player == computer)
    {
        std::cout<<"\nplayer = " << player;
        std::cout<<"\ncomputer = " << computer;
        std::cout<<"\nWon friendship!\n\n";
    }
    else
    {
        std::cout<<"\nplayer = " << player;
        std::cout<<"\ncomputer = " << computer;
        std::cout<<"\nLooser!\n\n";
    }

    return 0;
}
