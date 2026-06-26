#include <bits/stdc++.h>
using namespace std;

// Optimal. T.C -> O(n), S.C -> O(1).
bool isIsomorphic(string s, string s1)
{
    int m1[256] = {0}, m2[256] = {0};
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        if (m1[s[i]] != m2[s1[i]])
            return false;
        m1[s[i]] = i + 1;
        m2[s1[i]] = i + 1;
    }
    return true;
}

int main()
{
    string s = "paper", s1 = "title";
    cout << isIsomorphic(s, s1) << endl;
    return 0;
}