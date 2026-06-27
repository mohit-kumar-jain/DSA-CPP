#include <bits/stdc++.h>
using namespace std;
// Brute. T.C -> O(nlogn), S.C -> O(1).
// bool isAnagram(string s, string s1)
// {
//     if (s.size() != s1.size())
//         return false;
//     sort(s1.begin(), s1.end());
//     sort(s.begin(), s.end());
//     if (s == s1)
//         return true;
//     return false;
// }

// Optimal. T.C -> O(n), S.C -> O(1).
bool isAnagram(string s, string s1)
{
    if (s.size() != s1.size())
        return false;
    int m1[26] = {0};
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        m1[s[i] - 'a']++;
        m1[s1[i] - 'a']--;
    }
    for (int i = 0; i < 26; ++i)
    {
        if(m1[i] != 0){
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "ggii", s1 = "ttii";
    cout << isAnagram(s, s1) << endl;
    return 0;
}