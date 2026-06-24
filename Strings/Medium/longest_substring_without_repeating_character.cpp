#include <bits/stdc++.h>
using namespace std;
// Brute. T.C. -> O(n*n*n), S.C -> O(1).
// int longSubString(string s) {
//     int n = s.size();
//     int maxLen = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = i; j < n; j++) {
//             vector<bool> seen(256, 0);
//             bool unique = 1;
//             for (int k = i; k <= j; k++) {
//                 if (seen[s[k]]) {
//                     unique = 0;
//                     break;
//                 }
//                 seen[s[k]] = 1;
//             }
//             if (unique) {
//                 maxLen = max(maxLen, j - i + 1);
//             }
//         }
//     }
//     return maxLen;
// }

// Better. T.C. -> O(n*n), S.C -> O(1).
// int longSubString(string s) {
//     int n = s.size();
//     int maxLen = 0;
//     for (int i = 0; i < n; i++) {
//         vector<bool> seen(256, 0);
//         for (int j = i; j < n; j++) {
//             if (seen[s[j]])
//                 break;
//             seen[s[j]] = 1;
//             maxLen = max(maxLen, j - i + 1);
//         }
//     }
//     return maxLen;
// }

// Optimal. T.C. -> O(n), S.C -> O(len).
int longSubString(string s){
    int first = 0, second = 0,len = -1, n = s.size();
    if(n == 0) return -1;
    vector<bool> alpha(256,0);
    while(second < n){
        if(alpha[s[second]]){
            alpha[s[first]] = 0;
            first++;
        }
        len = max(len,second - first + 1);
        alpha[s[second]] = 1;
        second++;
    }
    return len;
}

int main()
{
    string s = "abcdefabcdefg";
    cout << longSubString(s) << endl;
    return 0;
}