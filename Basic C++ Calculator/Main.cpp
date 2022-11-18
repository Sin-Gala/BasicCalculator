#include <iostream>
#include <string>
#include "Calculator.h"

using namespace std;

int main()
{
    double x = 0.0;
    double y = 0.0;
    double result = 0.0;
    char oper = '+';

    string prompt;

    cout << "Calculator Console Application" << endl << endl;
    cout << "Please enter the operation to perform." << endl << endl;
    cout << "Format: a+b | a-b | a*b | a/b" << endl;

    Calculator c;
    while (true)
    {
        cin >> prompt;

        if (prompt.size() % 2 != 0)
            result = c.Calculate(prompt);

        cout << "Result is: " << result << endl;
    }

    return 0;
}
