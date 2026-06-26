#include<bits/stdc++.h>     
using namespace std;
  
//Brute. T.C -> O(nm), S.C -> O(1).
// bool isSubstring(string text, string pattern)
// {
//     int n = text.size();
//     int m = pattern.size();
//     for (int i = 0; i <= n - m; i++)
//     {
//         int j = 0;
//         while (j < m && text[i + j] == pattern[j])
//             j++;
//         if (j == m)
//             return true;
//     }
//     return false;
// }
// int repeatedMatch(string txt, string pattern)
// {
//     string temp = txt;
//     int repeat = 1;
//     while (temp.size() < pattern.size())
//     {
//         temp += txt;
//         repeat++;
//     }
//     if (isSubstring(temp, pattern))
//         return repeat;
//     if (isSubstring(temp+txt, pattern))
//         return repeat + 1;
//     return -1;
// } 

// Optima. T.C -> O(m+n), S.C -> O(n).
void LPS(vector<int>& lps, string pattern)
{
    int pre = 0, suf = 1, len = pattern.size();
    while (suf < len)
    {
        if (pattern[pre] == pattern[suf])
        {
            lps[suf] = pre + 1;
            suf++;
        }
        else
        {
            if (pre == 0)
            {
                lps[suf] = 0;
                suf++;
            }
            else
            {
                pre = lps[pre - 1];
            }
        }
    }
}

bool KMPSearch(string txt, string pattern)
{
    int n = pattern.size();
    vector<int> lps(n, 0);
    LPS(lps, pattern);
    int first = 0, second = 0;
    while (first < txt.size())
    {
        if (txt[first] == pattern[second])
        {
            first++,second++;
            if (second == n)
                return true;
        }
        else
        {
            if (second == 0)
                first++;
            else
                second = lps[second - 1];
        }
    }
    return false;
}

int repeatedMatch(string txt, string pattern)
{
    string temp = txt;
    int repeat = 1;
    while (temp.size() < pattern.size())
    {
        temp += txt;
        repeat++;
    }
    if (KMPSearch(temp, pattern))
        return repeat;
    if (KMPSearch(temp + txt, pattern))
        return repeat + 1;
    return -1;
}

int main() {
    string txt = "abcd";
    string pattern = "cdabcdab";
    cout << repeatedMatch(txt,pattern) << endl;
    return 0;
}