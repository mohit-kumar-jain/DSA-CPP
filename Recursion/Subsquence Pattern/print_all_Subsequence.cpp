#include <bits/stdc++.h>
using namespace std;

// Optimal. T.C -> O(n * 2 ^ n), S.C -> O(n * 2 ^ n).
// 1. Using Bit - Manipulation.
// vector<string> getSubsequences(string s){
//     vector<string> seq;
//     for (int i = 0; i < (1 << s.size()); i++)
//     {
//         string sub = "";
//         for (int j = 0; j < s.size(); j++)
//         {
//             if(i & (1 << j)) sub += s[j];
//         }
//         seq.push_back(sub);
//     }
//     return seq;
// }

// Optimal. T.C -> O(n * 2 ^ n), S.C -> O(n * 2 ^ n).
// 2. Using Recursion.
void helper(string &s, int index, string current, vector<string> &result)
{
    if (index >= s.size())
    {
        result.push_back(current);
        return;
    }
    helper(s, index + 1, current, result);
    current.push_back(s[index]);
    helper(s, index + 1, current, result);
    current.pop_back();
}

vector<string> getSubsequences(string s)
{
    vector<string> result;
    string current = "";
    helper(s, 0, current, result);
    return result;
}

int main()
{
    string s = "abc";
    vector<string> subsequences = getSubsequences(s);
    for (auto &subseq : subsequences)
    {
        cout << "\"" << subseq << "\"" << " ";
    }
    return 0;
}