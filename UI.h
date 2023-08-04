#pragma once
#include<iostream>
#include <string>

#include <limits>

#include "User.cpp"

#include "Class.cpp"

#include "Assignment.cpp"

#include "Submission.cpp"

#include "GradeBook.cpp"

#include "FileManager.cpp"

#include "Notification.cpp"

#include "UI.h"

#include "linking.cpp"

#include "Linking_CLass.cpp"

#include <windows.h>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"


#include <string>

using namespace std;
class UI{
public:
void StartProgram();    


/*The code defines two functions: is_to_delay(int dur) and is_to_dealy(). is_to_delay(int dur) creates a is_to_delay in the program execution for the specified duration (in seconds).
 is_to_dealy() prompts the user to press Enter to continue and clears the console screen.*/
void is_to_delay(int dur)
{
    int temp = time(NULL) + dur;
    while (temp > time(NULL))
        ;
}

void is_to_dealy()
{
    cout << "Press Enter to continue: ";
    cin.ignore();
    system("cls");
}

string mainmenu = " ##     ##    ###    #### ##    ##    ##     ## ######## ##    ## ##     ##\n ###   ###   ## ##    ##  ###   ##    ###   ### ##       ###   ## ##     ##\n #### ####  ##   ##   ##  ####  ##    #### #### ##       ####  ## ##     ##\n ## ### ## ##     ##  ##  ## ## ##    ## ### ## ######   ## ## ## ##     ##\n ##     ## #########  ##  ##  ####    ##     ## ##       ##  #### ##     ##\n ##     ## ##     ##  ##  ##   ###    ##     ## ##       ##   ### ##     ##\n ##     ## ##     ## #### ##    ##    ##     ## ######## ##    ##  #######\n";
string student_portal = "        ######  ######## ##     ## ########  ######## ##    ## ########    ########   #######  ########  ########    ###    ##\n       ##    ##    ##    ##     ## ##     ## ##       ###   ##    ##       ##     ## ##     ## ##     ##    ##      ## ##   ##\n       ##          ##    ##     ## ##     ## ##       ####  ##    ##       ##     ## ##     ## ##     ##    ##     ##   ##  ##\n        ######     ##    ##     ## ##     ## ######   ## ## ##    ##       ########  ##     ## ########     ##    ##     ## ##\n             ##    ##    ##     ## ##     ## ##       ##  ####    ##       ##        ##     ## ##   ##      ##    ######### ##\n       ##    ##    ##    ##     ## ##     ## ##       ##   ###    ##       ##        ##     ## ##    ##     ##    ##     ## ##\n        ######     ##     #######  ########  ######## ##    ##    ##       ##         #######  ##     ##    ##    ##     ## ########\n";
string teacher_portal = "       ######## ########    ###     ######  ##     ## ######## ########     ########   #######  ########  ########    ###    ##\n          ##    ##         ## ##   ##    ## ##     ## ##       ##     ##    ##     ## ##     ## ##     ##    ##      ## ##   ##\n          ##    ##        ##   ##  ##       ##     ## ##       ##     ##    ##     ## ##     ## ##     ##    ##     ##   ##  ##\n          ##    ######   ##     ## ##       ######### ######   ########     ########  ##     ## ########     ##    ##     ## ##\n          ##    ##       ######### ##       ##     ## ##       ##   ##      ##        ##     ## ##   ##      ##    ######### ##\n          ##    ##       ##     ## ##    ## ##     ## ##       ##    ##     ##        ##     ## ##    ##     ##    ##     ## ##\n          ##    ######## ##     ##  ######  ##     ## ######## ##     ##    ##         #######  ##     ##    ##    ##     ## ########\n";
void loadcntrl(int a)
{
    cout << GREEN << "         {";
    for (int i = 0; i < a; i++)
    {
        is_to_delay(1);
        cout << RED << "    *";
    }
    cout << GREEN << "         }";
}

void load(int a)
{
    loadcntrl(a);
}
/*The load(int a) function and fakeLoading(int duration, int interval)
functions are used to simulate loading animations and delays.*/
void fakeLoadingcntrl(int duration, int interval = 100)
{

    int totalTicks = duration * 1000 / interval;
    double a = 1;
    for (int tick = 0; tick < totalTicks; ++tick)
    {
        float progress = static_cast<float>(tick + 1) / totalTicks;
        int barWidth = 30;
        int numBars = static_cast<int>(progress * barWidth);

        std::cout << "\r[";
        for (int i = 0; i < barWidth; ++i)
        {
            if (i < numBars)
                std::cout << "#";
            else
                std::cout << " ";
        }
        std::cout << "] " << static_cast<int>(progress * 100) << "%";
        std::cout.flush();

        a += 1;
        if (a > 15)
        {
            is_to_delay(1);
            a = 0;
        }
    }
    std::cout << std::endl
              << RED << "Loading complete!" << YELLOW << std::endl;
}

void fakeLoading(int duration, int interval = 100)
{
    fakeLoadingcntrl(duration, interval);
}
};
