#include <bits/stdc++.h>
using namespace std;

int minChanges(string s)
{
    int changes = 0;
    for (int i = 0; i < s.length(); i += 2)
    {
        if (s[i] != s[i + 1])
        {
            changes++;
        }
    }
    return changes;
}

int main()
{
    string s = "1001";
    cout << minChanges(s) << endl;
    return 0;
}