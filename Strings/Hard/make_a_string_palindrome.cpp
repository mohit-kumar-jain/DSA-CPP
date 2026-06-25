#include<bits/stdc++.h>                   
using namespace std;
// Brute. T.C -> O(n*n), S.C -> O(1).
// bool isPalindrome(string &s, int end)
// {
//     int i = 0, j = end;
//     while (i < j)
//     {
//         if (s[i] != s[j])
//             return false;
//         i++,j--;
//     }
//     return true;
// }
// int strLen(string s)
// {
//     int n = s.size();
//     for (int i = n - 1; i >= 0; i--)
//     {
//         if (isPalindrome(s, i))
//             return n - i - 1;
//     }
//     return n - 1;
// }

// Optimal. T.C -> O(n), S.C -> O(n).
int LPS(string s){
    int pre = 0, suf = 1;
    vector<int>lps (s.size(),0);
    while(suf < s.size()){
        if (s[pre] == s[suf])
        {
            lps[suf] = pre + 1;
            pre++,suf++;
        }else{
            if(pre == 0){
                suf++;
            }else{
                pre = lps[pre - 1];
            }
        }
    }
    return lps[s.size()-1];
}      

int strLen(string s){
    int len  = s.size();
    string  rev = s;
    reverse(rev.begin(),rev.end());
    s += '$';
    s += rev;
    cout<<s<<endl;
    len = len - LPS(s);
    return len;
}

int main() {
    string s = "abca";
    cout << strLen(s) << endl;
    return 0;
}