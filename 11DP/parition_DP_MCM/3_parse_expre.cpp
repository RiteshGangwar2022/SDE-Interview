#include <bits/stdc++.h>
using namespace std;

int parseBoolExpr(string str)
{

    stack<char> s;

    // store everything in stack avoid paranthesis and ,=>

    for (int i = 0; i < str.size(); i++)
    {

        if (str[i] == ')')
        {

            // act upon operator based on true or false getting from stack

            int t = 0;
            int f = 0;

            // pop all the t and f from stack, and, maintain the final value using variables t and f
            while (s.top() == 't' || s.top() == 'f')
            {

                if (s.top() == 't')
                {
                    t = 1;
                }
                else
                {
                    f = 1;
                }
                s.pop();
            }

            // pop the operator
            char op = s.top();
            s.pop();

            // act according to operator and t and f

            if (op == '&')
            {

                if (f)
                {
                    s.push('f');
                }
                else
                {
                    s.push('t');
                }
            }

            if (op == '!')
            {

                if (t)
                {
                    s.push('f');
                }
                else
                {
                    s.push('t');
                }
            }
            if (op == '|')
            {

                if (t)
                {
                    s.push('t');
                }
                else
                {
                    s.push('f');
                }
            }
        }
        else if (str[i] != ',' && str[i] != '(')
        {
            s.push(str[i]);
        }
    }

    if (s.top() == 't')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string str;
    cin >> str;

    bool res = parseBoolExpr(str);

    if (res)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}