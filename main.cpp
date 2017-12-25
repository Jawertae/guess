#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <iomanip>

//include some headers for random number
//generation and for taking input from user

//By awesomesocrates & jawertae


using namespace std;

int main()
{

    int num=10,roof=10,round=1,diff=0;
    int answer,guess,low,high;
    char repeat='y';

    bool win = false;

    //initializes the random seed
    srand( time(NULL) );


    while(diff<1||diff>3)
    {
        cout << "Easy? (1) Medium? (2) or Hard? (3): ";
        cin >> diff;
    }
    

    while(guess!=-1)
    {
        //makes answer a random int between 1 and roof
        answer = rand() % roof + 1;

        cout << setw(15) << "\e[1m" << "\e[44m" << "########" << "\e[0m\n"
            << setw(15) << "\e[1m" << "\e[44m" << "ROUND " << setw(2) << round << "\e[0m\n" 
            << setw(15) << "\e[1m" << "\e[44m" << "########" << "\e[0m\n" << endl;

        cout << "Guess a number between 1 and " << roof << endl;

        cout << "\tEnter -1 to quit\n" << endl;

        low=0;
        high=roof;

        //cout << "HINT: The answer is " << answer << endl;

        for( int i = 0; i < num; i++)
        {
            cout << "Guesses left: ";

            if (num-i <= num/3)
            {
                cout << "\e[1m" << "\e[31m";
            }
            else if (num-i <= num*2/3)
            {
                cout << "\e[1m" << "\e[33m";
            }
            else
            {
                cout << "\e[1m" << "\e[32m";
            }

            cout << num-i << "\e[0m" << endl;

            cout << "Guess";

            if(diff!=3)
            {
                cout << " between " << low << " and " << high;
            }
            if(diff==1)
            {
                cout << " (" << (low+high)/2 << ")";
            }

            cout << ": ";

            cin >> guess;

            if( guess == -1 || ( num - i == 1 && guess != answer))
            {
                break;
            }
            else if(guess==answer)
            {
                cout << "\e[1m" << "\e[34m\n" << setw(24) << "################\n" << setw(24) << 
                    "That was correct\n" << setw(24) << "################\n" << "\e[0m" << endl;
                win=true;
                break;
            }
            else if(guess > answer)
            {
                cout <<"\e[1m" << "\e[31m\n" << setw(22) << "############\n" << setw(22) << 
                    "Guess  Lower\n" << setw(22) << "############\n" << "\e[0m" << endl;
                if(guess < high ){high=guess;}
                win=false;
            }
            else if(guess < answer)
            {
                cout <<"\e[1m" << "\e[31m\n" << setw(22) << "############\n" << setw(22) << 
                    "Guess Higher\n" << setw(22) << "############\n" << "\e[0m" << endl;
                if(guess > low ){low=guess;}
                win=false;
            }
            else
            {
                //should never get here
            }
            
        }

        if (guess!= -1)
        {

            if(win)
            {
                roof*=2;

                if (roof >= INT_MAX/2)
                {
                    cout << "You're too good for this game." << endl;
                    break;
                }
                if(diff==1)
                {
                    num++;
                }
                if(diff==2)
                {
                    if(round%5==0)
                    {
                        num++;
                    }
                }
                round++;
            }

            if(!win)
            {
            cout << "\e[0m" << "\e[33m\n" << setw(24) <<
                "################\n" << setw(24) << 
                "You lose! Loser!\n" << setw(24) << 
                "You win NOTHING!\n" << setw(24) << 
                "################\n" << "\e[0m" << endl;

            }

        }
        else
        {
            repeat = 'n';
            cout << "\e[0m" << "\e[33m" << setw(27) << "######################\n" << setw(27) << "Nobody likes a quitter\n" << setw(27) << "######################\n" << "\e[0m";
        }
    }
}

