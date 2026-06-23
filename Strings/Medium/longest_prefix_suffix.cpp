#include<bits/stdc++.h>        
using namespace std;
// Brute . T.C -> O(n*n), S.C -> O(1)  
// int LPS(string s) {
//     int n = s.size();
//     int ans = 0;
//     for (int len = 1; len < n; len++) {
//         int left = 0;
//         int right = n - len;
//         while (left < len && s[left] == s[right]) {
//             left++;
//             right++;
//         }
//         if (left == len)
//             ans = len;
//     }
//     return ans;
// }

// Optimal . T.C -> O(n), S.C -> O(n)  
int LPS(string s){
    int pre = 0,suf = 1,n = s.size();
    if(n == 0) return -1;
    vector<int> lps(n,0);
    while(suf < n){
        if(s[pre] == s[suf] ){
            lps[suf] = pre + 1;
            pre++,suf++;
        }else{
            if(pre == 0){
                lps[suf] = 0;
                suf++;
            }else{
                pre = lps[pre-1];
            }
        }
    }
    return lps[n-1];
}

int main() {
    string s = "aba";
    cout << LPS(s) << endl;
    return 0;
}