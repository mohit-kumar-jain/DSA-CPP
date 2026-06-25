#include <bits/stdc++.h>
using namespace std;
// Brute. T.C -> O(n*n*n), S.C -> O(1).
// int smallString(string s){
//     int n = s.size();
//     if (n == 0) return 0;
//     int totalDistinct = 0;
//     int alpha[256] = {0};
//     for (char c : s)
//     {
//         if (alpha[c] == 0)
//             totalDistinct++;
//         alpha[c]++;
//     }
//     int ans = n;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             int windowalpha[256] = {0};
//             int distinct = 0;
//             for (int k = i; k <= j; k++)
//             {
//                 if (windowalpha[s[k]] == 0)
//                     distinct++;
//                 windowalpha[s[k]]++;
//             }
//             if (distinct == totalDistinct)
//                 ans = min(ans, j - i + 1);
//         }
//     }
//     return ans;
// }

// Better. T.C -> O(n*n), S.C -> O(1).
// int smallString(string s)
// {
//     int n = s.size();
//     if (n == 0) return 0;
//     int totalDistinct = 0;
//     int alpha[256] = {0};
//     for (char c : s)
//     {
//         if (alpha[c] == 0)
//             totalDistinct++;
//         alpha[c]++;
//     }
//     int ans = n;
//     for (int i = 0; i < n; i++)
//     {
//         int windowalpha[256] = {0};
//         int distinct = 0;
//         for (int j = i; j < n; j++)
//         {
//             if (windowalpha[s[j]] == 0)
//                 distinct++;
//             windowalpha[s[j]]++;
//             if (distinct == totalDistinct)
//             {
//                 ans = min(ans, j - i + 1);
//                 break;
//             }
//         }
//     }
//     return ans;
// }

// Optimal. T.C -> O(n), S.C -> O(1).
int smallString(string s)
{
    int n = s.size(), first = 0, second = 0;
    if (n == 0)
        return 0;
    vector<int> alpha(256, 0);
    int mini = n,diff = 0;
    while (first < n)
    {
        if(alpha[s[first]] == 0)    
            diff++;
        alpha[s[first]]++;
        first++;
    }
    for (int i = 0; i < 256; i++)
    {
        alpha[i] = 0;
    }
    first = 0;
    while(second < n){
        while (diff && second < n)
        {
            if(alpha[s[second]] == 0)
                diff--;
            alpha[s[second]]++;
            second++;
        }
        mini = min(mini,second - first);
        while(diff != 1){
            mini = min(mini,second - first);
            alpha[s[first]]--;
            if(alpha[s[first]] == 0)
                diff++;
            first++;
        }
    }
    return mini;
}

int main()
{
    string s = "abcabdc";
    cout << smallString(s) << endl;
    return 0;
}