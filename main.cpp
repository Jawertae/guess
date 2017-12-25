#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <iomanip>

//include some headers for random number
//generation and for taking input from user

//By awesomesocrates & jawertae

using namespace std;

bool VISUAL_MODE = true;

int chooseDifficulty();
void optionMenu();
void numberLine(int,int);
void numberPlot(int,int,int);
void subLine(int,int,int,int);

int main()
{

    int num=10, roof=10, round=1, diff=0; //initial definitions.
    int answer, guess, low, high; //declarations only. they are defined before they are called
    bool win = false;

    //initializes the random seed
    srand( time(NULL) );

    //numberLine(0,10,3);

    diff = chooseDifficulty();

    while(guess!=-1)
    {
        //makes answer a random int between 1 and roof
        answer = rand() % roof + 1;

        cout //TODO: Clean this up.
            << setw(16) << "\e[1m" << "\e[44m" << "########" << "\e[0m" << endl
            << setw(16) << "\e[1m" << "\e[44m" << "ROUND " << setw(2) << round << "\e[0m" << endl 
            << setw(16) << "\e[1m" << "\e[44m" << "########" << "\e[0m" << endl << endl;

        //numberLine(0,roof);

        cout << "Guess a number between 1 and " << roof << endl;

        cout << "\tEnter -1 to quit" << endl << endl;

        //(re)initialize low and high
        low=0;
        high=roof;

        //THIS IS FOR DEBUGGING. UNCOMMENT TO CHEAT.
        //cout << "HINT: The answer is " << answer << endl;


        //for loop to take gusses until guesses run 
        //out or a correct answer is guessed
        for( int i = 0; i < num; i++)
        {
            if(VISUAL_MODE)
            {
                if (diff==2)
                {
                    subLine(0,roof,low,high);
                }
                else if (diff==1)
                {
                    numberLine(low,high);
                }
            }
            cout << "Guesses left: ";
            if (num-i <= num/3)
            {
                //red for bottom third
                cout << "\e[1m" << "\e[31m";
            }
            else if (num-i <= num*2/3)
            {
                //yellow for middle third
                cout << "\e[1m" << "\e[33m";
            }
            else
            {
                //green for top third
                cout << "\e[1m" << "\e[32m";
            }
            cout << num-i << "\e[0m" << endl;

            cout << "Guess";
            if(diff!=3) //for medium and easy, show bounds
            {
                cout << " between " << low << " and " << high;
            }
            if(diff==1) //for easy, show median
            {
                cout << " (" << (low+high)/2 << ")";
            }
            cout << ": ";
            cin >> guess;

            if(VISUAL_MODE)
            {
                if(diff==3){numberLine(0,roof);}
                else if(diff==2){subLine(0,roof,low,high);}
                else{numberLine(low,high);}
                if(diff!=1)
                {
                    numberPlot(0,roof,guess);
                }
                else
                {
                    numberPlot(low,high,guess);
                }
            }
            //if user wants to escape, or if its the last
            //guess and its wrong, break out before we give
            //results about the guess. Loss is inferred
            if( guess == -1 || ( num - i == 1 && guess != answer))
            {
                break;
            }
            else if(guess==answer) //if user guessed correctly
            {
                cout << "\e[1m" << "\e[34m" << endl //Light Blue
                    << setw(24) << "################" << endl 
                    << setw(24) << "That was correct" << endl 
                    << setw(24) << "################" << endl 
                    << "\e[0m" << endl;

                win=true;
                break;
            }
            else if(guess > answer) //if they guessed too high
            {
                cout << "\e[1m" << "\e[31m" << endl //Light Red
                    << setw(22) << "############" << endl 
                    << setw(22) << "Guess  Lower" << endl 
                    << setw(22) << "############" << endl 
                    << "\e[0m" << endl;

                //adjust ceiling if the new ceiling is lower than old one
                if(guess < high ){high=guess;}
                win=false;
            }
            else //guess < answer //if they guessed too low
            {
                cout << "\e[1m" << "\e[31m" << endl //Light Red
                    << setw(22) << "############" << endl 
                    << setw(22) << "Guess Higher" << endl 
                    << setw(22) << "############" << endl 
                    << "\e[0m" << endl;

                //adjust floor if the new floor is higher than old one
                if(guess > low ){low=guess;} 
                win=false;
            }
            
        }

        if (guess!= -1) //assume game goes on unless user choooses -1
        {
            if(win) //if they guessed correctly
            {
                roof*=2; //double the current pool of possible answers

                if (roof >= INT_MAX/2) //stop game at half of max int
                {
                    cout << "You're too good for this game." << endl;
                    break;
                }
                if(diff==1)
                {
                    num++; //increases max guesses every round for easy
                }
                if(diff==2)
                {
                    if(round%5==0)
                    {
                        num++; //increases max guesses every 5 rounds on medium
                    }
                }
                round++;
            }

            if(!win) //if they exceeded their guesses, we start over on the same round
            {
            cout << "\e[0m" << "\e[33m" << endl 
                << setw(24) << "################" << endl 
                << setw(24) << "You lose! Loser!" << endl 
                << setw(24) << "You win NOTHING!" << endl
                << setw(24) << "################" << endl 
                << "\e[0m" << endl;
            }

        }
        else //this is what happens when user enters -1 and wants to quit
        {
            cout << "\e[0m" << "\e[33m" 
                << setw(27) << "######################" << endl 
                << setw(27) << "Nobody likes a quitter" << endl 
                << setw(27) << "######################" << endl 
                << "\e[0m";
        }
    }
}


int chooseDifficulty()
{
    int choice = 0;
    while (choice != -1 || choice < 1 || choice > 5 )
    {
        cout 
            << "Enter a number to continue." << endl
            << "Easy     (1)" << endl
            << "Medium   (2)" << endl
            << "Hard     (3)" << endl
            << "Classic  (4)" << endl
            << "Insanity (5)" << endl
            << "Options  (6)" << endl
            << "Quit    (-1)" << endl;
        cin >> choice;
        if (choice==6)
        {
            //enter option menu here
        }
    }
    return  choice;
}


void numberLine(int l,int h)
{
    //"<-|--------------------+--------------------|->"

    cout << "<-" << setfill('-') << left 
        << setw(5) << l << right 
        << setw(13) << ((float)l+(float)h)/(float)2
        << setw(18) << h << "->" << endl << setfill(' ');
}


void numberPlot(int l, int h, int g)
{
    int width=2+(36*(g-l)/(h-l));
    //numberLine(l,h);
    if(width > 0 && width < 40)
    {
        cout << setw(width) << "^" << g << endl;
    }
    else
    {
        cout << g << "?" << endl;
    }
}

void subLine(int l,int h,int f,int c)
{
    int floorw=2+(36*(f-l)/(h-l));
    int ceilingw=(2+(36*(c-l)/(h-l)))-floorw;

    numberLine(l,h);
    cout 
        << setw(floorw) << "|" << setfill('-')
        << setw(ceilingw) << "|" << endl << setfill(' ');
}
