#include<bits/stdc++.h>        
using namespace std;

// Brute. T.C -> O(n*n*n), S.C. -> O(n).
// bool isPalindrome(string s, int left, int right){
//     while (left < right)
//     {
//         if(s[left] != s[right])
//             return false;
//         left++,right--;
//     }
//     return true;
// }
// string longestSubstring(string s){
//     string res = "";
//     for (int i = 0; i < s.size(); i++)
//     {
//         for (int j = i; j < s.size(); j++)
//         {
//             if(isPalindrome(s,i,j)){
//                 if((j - i +  1) > res.size())
//                     res = s.substr(i,j+1);
//             }   
//         }
//     }
//     return res;
// }

// Better. T.C -> O(n*n), S.C. -> O(1).
int isPalindrome(string& s, int left, int right){
    while (left >= 0 && right < s.size() && s[left] == s[right])
    {
        left--,right++;
    }
    return (right - left - 1);
}

string longestSubstring(string s){
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int odd = isPalindrome(s,i,i);
        int even = isPalindrome(s,i,i+1);
        int len = max(even,odd);
        if(len > (end - start)){
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substr(start,end - start + 1);
}

int main() {
    string s = "babad";
    cout << longestSubstring(s) << endl;    
    return 0;
}