#include <iostream>
#include <time.h>

using namespace std;

int lucky_number = time(0) % 10 + 1;
int  score = 5;

bool play_again()
{

    char answer;
    cout << "----------------------------" << endl;
    cout << "Do you want to play again? (y/n): ";
    cin >> answer;

    switch (answer)
    {
    case 'y':
    {
        cout << "-----------------" << endl;
        cout << "Let's play again!" << endl;
        cout << "-----------------" << endl;
        return true;
    }
    case 'n':
    {
        cout << "-------------------" << endl;
        cout << "Thanks for playing!" << endl;
        cout << "-------------------" << endl;
        cin.get();
        return false;
    }
    default:
    {
        cout << "Invalid input. Please try again." << endl;
        play_again();
    }
    }
}

bool guessing()
{

    int guess;
    cout << "Guess the lucky number: ";
    cin >> guess;

    if (guess > 10  ||  guess < 1)
    {
        cout << "** INVALID - Please enter a number between 1 - 10 only" << endl;
        guessing();
    }
    else
    {

        if(guess == lucky_number)
        {
            cout << "*****************************************************" << endl;
            cout << "Your guess is " << guess << " and it's right" << endl;
            cout << "*****************************************************" << endl;
            cout << endl;
            cout << "Your score on lucky scale is " << score << endl;
            cout << "*****************************************************" << endl;
            cout << endl;

            bool answer = play_again();
            return answer;


        }
        else
        {
            cout << "Your guess is " << guess << " and it's wrong" << endl;
            cout << "Try Again" << endl;
            cout << endl;
            score = score - 1;
            cout << "Chances left: " << score << endl;
            
            if (score <= 0)
            {
                cout << ".............................." << endl;
                cout << "You have no more chances left" << endl;
                cout << "You Lost!" << endl;
                cout << ".............................." << endl;

                 bool answer = play_again();
                return answer;
            }
            else
            {
                guessing();
            }
        }
    }

}

int main()
{
    cout << lucky_number << endl;
    cout << "----------------------------" << endl;
    cout << "*** Welcome to the game ***" << endl;
    cout << "----------------------------" << endl;
    cout << endl;
    cout << "You have 5 chances to guess the lucky number" << endl;
    cout << "Number will be between 1 and 10*" << endl;
    cout << "Good Luck! ~_~" << endl;
    cout << endl;
    cout << "----------------------------" << endl;

    bool user_choice = guessing();

    if (user_choice)
    {
        main();
    }
    else
    {
        return 0;
    }

}