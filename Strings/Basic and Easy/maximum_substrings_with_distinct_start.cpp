#include <bits/stdc++.h>
using namespace std;
int maxDistinct(string s)
{
    vector<int> seen(26, 0);
    int count = 0;
    for (const auto &c : s)
    {
        if (seen[c - 'a'])
            continue;
        else
        {
            seen[c - 'a']++;
            count++;
        }
    }
    return count;
}
int main()
{
    cout << maxDistinct("abcdabss") << endl;
    return 0;
}