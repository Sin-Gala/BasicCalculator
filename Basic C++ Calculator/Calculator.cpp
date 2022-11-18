#include "Calculator.h"
#include <list>
#include <string>

using namespace std;

double Calculator::Calculate(string prompt)
{
    double result = 0.0;
    list<double> nums;
    list<double> oper;

    string fullNum = "";

    // Break the string into two lists
    for (int i = 0; i < prompt.size(); i++)
    {
        switch (prompt[i])
        {
            case '+':
            case '-':
            case '*':
            case '/':
                if (fullNum != "")
                {
                    double x = stod(fullNum);
                    nums.push_back(x);
                    fullNum = "";
                }
                oper.push_back(prompt[i]);
                break;
            default:
                fullNum += prompt[i];
                break;
        }            
    }

    // Calculate the result
    for (int i = 0; i < oper.size(); i++)
    {
        double n1 = 0.0;

        if (i == 0)
            n1 = *next(nums.begin(), i);
        else
            n1 = result;

        double n2 = *next(nums.begin(), i + 1);
        char op = *next(oper.begin(), i);

        switch (op)
        {
        case '+':
            result = n1 + n2;
            break;
        case '-':
            result = n1 - n2;
            break;
        case '*':
            result = n1 * n2;
            break;
        case '/':
            result = n1 / n2;
            break;
        default:
            result = result;
        }
    }

    return result;
}
