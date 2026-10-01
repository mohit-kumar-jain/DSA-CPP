#include <bits/stdc++.h>
using namespace std;

// T.C -> O(N), S.C -> O(N).
bool isValid(string s)
{
    stack<int> par;
    stack<int> star;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            par.push(i);
        }
        else if (s[i] == '*')
        {
            star.push(i);
        }
        else
        {
            if (!par.empty())
            {
                par.pop();
            }
            else if (!star.empty())
            {
                star.pop();
            }
            else
            {
                return false;
            }
        }
    }
    while (!par.empty() && !star.empty())
    {
        if (par.top() < star.top())
        {
            par.pop();
            star.pop();
        }
        else
        {
            return false;
        }
    }
    return par.empty();
}

int main()
{
    string s = "(*))";
    isValid(s) ? cout << "True" << endl : cout << "False" << endl;
    return 0;
}