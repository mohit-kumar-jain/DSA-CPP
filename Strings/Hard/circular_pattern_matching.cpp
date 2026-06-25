#include<bits/stdc++.h>                   
using namespace std;
// Brute. T.C -> O(n*m), S.C -> O(1).
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
// bool circularMatch(string txt, string pat)
// {
//     int n = txt.size();
//     int m = pat.size();
//     if (m > n)
//         return false;
//     for (int start = 0; start < n; start++)
//     {
//         int j = 0;
//         while (j < m && txt[(start + j) % n] == pat[j])
//         {
//             j++;
//         }
//         if (j == m)
//             return true;
//     }
//     return false;
// }

// Better. T.C -> O(n+m), S.C -> O(2n).
// bool circularMatch(string txt, string pat)
// {
//     int n = txt.size();
//     int m = pat.size();
//     if (m > n)
//         return false;
//     string doubled = txt + txt;
//     return doubled.find(pat) != string::npos;
// }

// Optimal. T.C -> O(m+n), S.C -> O(m).
void LPS(vector<int>& lps,string s){
    if(s.size() == 0) return;
    int pre = 0, suf = 1,len = s.size();
    while(suf < len){
        if(s[pre] == s[suf]){
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
}
bool strMatch(string txt,string pattern){
    if(txt.size() == 0) return 0;
    int first = 0 ,second = 0,l1 = txt.size(),l2 = pattern.size();
    vector<int>lps (l2,0);
    LPS(lps,pattern);
    while (first < l1 && second < l2)
    {
        if(txt[first] == pattern[second]){
            first++,second++;
        }else{
            if(second == 0)
                first++;
            else
                second = lps[second - 1];
        }
    }
    if (second == l2)
        return 1;  
    return 0;
}
bool circularMatch(string txt, string pattern){
    txt += txt;
    if(strMatch(txt,pattern)){
        return 1;
    }
    return 0;
}

int main() {
    string txt = "cdearobab";
    string pattern = "ab";
    cout << circularMatch(txt,pattern) << endl;
    return 0;
}