#include "Calculator.h"
#include <list>
#include <string>

using namespace std;

// Break the string into two lists
void Calculator::SeparateString(std::string prompt)
{
    for (int i = 0; i < prompt.size(); i++)
    {
        switch (prompt[i])
        {
            case '+':
            case '-':
            case '*':
            case '/':
                SetNumber();
                oper.push_back(prompt[i]);
                continue;
            default:
                fullNum = fullNum + prompt[i];

                if (i != prompt.size() - 1)
                    continue;
                else
                    break;
        }

        SetNumber();
    }
}

void Calculator::SetNumber()
{
    if (fullNum == "") return;

    double x = stod(fullNum);
    nums.push_back(x);
    fullNum = "";
}

double Calculator::Calculate(string prompt)
{
    SeparateString(prompt);

    // TODO: Make the calculs respect the operation order
    // * / + -
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
