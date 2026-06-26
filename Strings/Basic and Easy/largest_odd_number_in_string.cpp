#include <bits/stdc++.h>
using namespace std;

// Optimal. T.C -> O(n), S.C -> O(1).
string largestOdd(string s)
{
    int ind = -1;
    int i;
    for (i = s.length() - 1; i >= 0; i--)
    {
        if ((s[i] - '0') % 2 == 1)
        {
            ind = i;
            break;
        }
    }
    if (ind == -1)
        return "";
    i = 0;
    while (i <= ind && s[i] == '0')
        i++;
    return s.substr(i, ind - i + 1);
}

int main()
{
    string s = "24689";
    cout << largestOdd(s) << endl;
    return 0;
}