#include "mon_calcul.hpp"
#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>

double apply(double a, double b, char op)
{
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

int priority(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double convertir(const string& str, double x)
{
    stack<double> values;
    stack<char> ops;

    for (int i = 0; i < str.length(); i++)
    {
        // nombre
        if (isdigit(str[i]))
        {
            double val = 0;
            while (i < str.length() && isdigit(str[i])) {
                val = val * 10 + (str[i] - '0');
                i++;
            }
            values.push(val);
            i--;
        }

        // variable x
        else if (str[i] == 'x')
        {
            values.push(x);
        }

        // parenthèses
        else if (str[i] == '(')
        {
            ops.push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(apply(a, b, op));
            }
            ops.pop(); // enlever '('
        }

        // opérateurs
        else
        {
            while (!ops.empty() && priority(ops.top()) >= priority(str[i]))
            {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(apply(a, b, op));
            }
            ops.push(str[i]);
        }
    }

    // finir calcul
    while (!ops.empty())
    {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(apply(a, b, op));
    }

    return values.top();
}
