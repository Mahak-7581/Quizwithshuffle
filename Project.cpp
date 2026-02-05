#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
using namespace std;
#include <string.h>
class login
{
private:
    string pass = "shinchan@98";

public:
    login()
    {
        cout << "....WELCOME..Miss Mahak.." << endl;
        cout << "\n";
    }
    void total(int score)
    {
        cout << "percentage is:" << (score * 100) / 10 << "%" << endl;
        cout << "\n";
    }
    void quiz()
    {
        cout << "....WELCOME TO QUIZ....\n\n";

        string questions[10] = {
            "What is the capital of India?",
            "Which number is a prime number?",
            "Value of pi is:",
            "5 * 6 = ?",
            "How many continents are there in the world?",
            "Which continent has largest population?",
            "Boiling point of water in Celsius is:",
            "Chemical formula of common salt:",
            "Which number is even number?",
            "Which language is mainly used for system programming?"};

        string options[10][4] = {
            {"Mumbai", "New Delhi", "Kolkata", "Chennai"},
            {"9", "15", "17", "21"},
            {"3.14", "6.78", "3", "1.24"},
            {"11", "25", "30", "35"},
            {"5", "6", "7", "8"},
            {"Asia", "Africa", "Antarctica", "Europe"},
            {"100", "95", "105", "90"},
            {"HCl", "KCl", "NaCl", "MgCl"},
            {"5", "9", "7", "8"},
            {"Python", "C", "HTML", "Java"}};

        // correct option index (0-based)
        int correctIndex[10] = {1, 2, 0, 2, 2, 0, 0, 2, 3, 1};

        char userAns[10];
        int score = 0;

        srand(time(0));

        for (int i = 0; i < 10; i++)
        {
            cout << "Q" << i + 1 << ") " << questions[i] << "\n";

            // store original correct answer
            string correctAnswer = options[i][correctIndex[i]];

            // shuffle options
            random_shuffle(options[i], options[i] + 4);

            // find new correct index after shuffle
            int newCorrectIndex;
            for (int j = 0; j < 4; j++)
            {
                if (options[i][j] == correctAnswer)
                {
                    newCorrectIndex = j;
                    break;
                }
            }

            // display options
            for (int j = 0; j < 4; j++)
            {
                cout << char('A' + j) << ") " << options[i][j] << "\n";
            }

            cout << "Answer: ";
            cin >> userAns[i];
            userAns[i] = toupper(userAns[i]);

            if ((userAns[i] - 'A') == newCorrectIndex)
            {
                score++;
            }

            cout << "\n";
        }

        total(score);
    }
    void Password()
    {
        string id;
        cout << "Enter Id->";
        cin >> id;
        string p;
        cout << "Enter Password->";
        cin >> p;
        cout << "\n";
        if (p == pass)
        {
            cout << "....You are verified.... \n";
            quiz();
        }
        else
        {
            cout << "Wrong password..try again\n";
        }
    }
};
int main()
{
    login q1;
    q1.Password();
    cout << "---THANK YOU---";
    return 0;
}