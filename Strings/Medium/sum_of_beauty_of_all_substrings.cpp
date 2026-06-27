#include <bits/stdc++.h>
using namespace std;

// Optimal. T.C -> O(n*n), S.C. -> O(1).
int sumSubStrings(string s)
{
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        unordered_map<char, int> freq;
        for (int j = i; j < s.size(); j++)
        {
            freq[s[j]]++;
            int mini = INT_MAX, maxi = INT_MIN;
            for (auto it : freq)
            {
                mini = min(mini, it.second);
                maxi = max(maxi, it.second);
            }
            sum += (maxi - mini);
        }
    }
    return sum;
}

int main()
{
    string s = "xyx";
    cout << sumSubStrings(s) << endl;
    return 0;
}