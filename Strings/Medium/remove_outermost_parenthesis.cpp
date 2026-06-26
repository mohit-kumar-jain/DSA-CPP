#include <bits/stdc++.h>
using namespace std;

// Optimal. T.C -> O(n), S.C -> O(1).
string removeOuter(string s)
{
    string res = "";
    int counter = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            counter += 1;
            if (counter > 1)
            {
                res += s[i];
            }
        }
        else if (s[i] == ')')
        {
            counter -= 1;
            if (counter > 0)
            {
                res += s[i];
            }
        }
    }
    return res;
}

int main()
{
    string s = "()(()())(())";
    cout << removeOuter(s) << endl;
    return 0;
}