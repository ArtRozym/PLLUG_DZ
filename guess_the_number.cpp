#include <QCoreApplication>
#include <iostream>
#include <string>
#include <time.h>

/*
Написати консольну гру "Вгадай число".
Гра має починатися з ігрового меню "[Level 1] Woul'd like to play? [p] - play, [l]- select level, [q] - quit.'".
На початку цього надпису - рівень складності, який можна змінювати (за замовчуванням, на початку гри == 1).
При введені:
"q" - вихід з програми
"p" - початок гри
"l" - меню вибору рівня (від 1 до 10) та повернення до ігорового меню
Гра полягає в наступному:
Комп'ютер випадковим чином обирає число у проміжку (числовий проміжок задежить від рівня складності)
Користувач має 10 спроб для того, щоб вгадати число. Кожну спробу користувач вводить число:
Якщо воно більше - користувач отримує у відповідь "Greater!"
Якщо воно меньше - користувач отримує у відповідь "Less"
Якщо воно рівне тому числу - то користувач виграв та отримує повідомлення "You win!".
Якщо користувач не виграв з 10 спроб, то програє.
Після програшу чи виграшу користувач повертається в ігрове меню.
*/

int main()
{
    bool playGame = false;
    bool qExitProgram = true;
    int level = 1;
    char choice = 't';
    int random=0;

    std::cout<< "Hi! It is game \"Guess the Number\"\n\n";

    while (qExitProgram)
    {
        int attempt =10;

        std::cout << "\n[Level"<<level<<"] Woul'd like to play? [p] - play, [l]- select level, [q] - quit\n";

        std::cin>>choice;

        if(choice=='p')
             playGame = true;
        else if(choice=='q')
             qExitProgram = false;
        else if(choice=='l')
        {
            std::cout<< "\nSelect a level from 1 to 10\n";
            std::cin>>level;

        }//else if(choice=='l')

        srand(time(NULL));
        random = rand() % (37*level) + 1;

        while(playGame)
        {
            std::cout<<"\nEnter a number from "<<1<<" to "<<37*level<<std::endl;
            int namber =0;
            std::cin>>namber;

            if(attempt!=0)
            {
                if(namber<random)
                {
                    std::cout<<"\nGreater!\n";
                    attempt--;
                    std::cout<<"\nAttempts: "<<attempt;
                }
                else if(namber>random)
                {
                    std::cout<<"\nLess!\n";
                    attempt--;
                    std::cout<<"\nAttempts: "<<attempt;
                }
                else if(namber==random)
                {
                    std::cout<<"\nYou win!\n";
                    playGame=false;
                }

            }//if(attempt!=0)
            else
            {
                std::cout <<"\nNumber = " <<random<<std::endl;
                playGame=false;
            }

        }//while(playGame)

    }//while (qExitProgram)


    return 0;
}//int main()
