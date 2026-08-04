#include <bits/stdc++.h>
using namespace std;
int firstUniqChar(string s)
{
    int mpp[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        mpp[s[i] - 'a']++;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (mpp[s[i] - 'a'] == 1)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    string s = "aabccdd";
    cout << firstUniqChar(s) << endl;
    return 0;
}