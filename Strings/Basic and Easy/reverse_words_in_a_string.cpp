#include <bits/stdc++.h>
using namespace std;

// Brute. T.C. -> O(N), S.C. -> O(N).
// string reverseWords(string s)
// {
//     string result = "";
//     int i = s.size() - 1;
//     while (i >= 0)
//     {
//         while (i >= 0 && s[i] == ' ')
//         {
//             i--;
//         }
//         if (i < 0)
//             break;
//         int end = i;
//         while (i >= 0 && s[i] != ' ')
//         {
//             i--;
//         }
//         string word = s.substr(i + 1, end - i);
//         if (!result.empty())
//         {
//             result += " ";
//         }
//         result += word;
//     }
//     return result;
// }

// Optimal. T.C. -> O(N), S.C. -> O(1).

string reverseWords(string s)
{
    reverse(s.begin(), s.end());
    int n = s.size();
    int left = 0;
    int right = 0;
    int i = 0;
    while (i < n)
    {
        while (i < n && s[i] == ' ')
            i++;
        if (i == n)
            break;
        while (i < n && s[i] != ' ')
        {
            s[right++] = s[i++];
        }
        reverse(s.begin() + left, s.begin() + right);
        s[right++] = ' ';
        left = right;
        i++;
    }
    s.resize(right - 1);
    return s;
}

int main()
{
    string s = "welcome to the jungle";
    string res = reverseWords(s);
    cout << res << endl;
    return 0;
}