#include<bits/stdc++.h>
using namespace std;
// Brute. T.C -> O(n*n), S.C -> O(1).
// bool isRotated(string s,string s1){
//     if(s.size() != s1.size()) return false;
//     for(int i = 0; i < s1.size();i++){
//         // This method uses space Complexity of O(1) because we don't store answer for every rotation.
//         // char c = s[0];
//         // for (int i = 0; i < s.size()-1; i++)
//         // {
//         //     s[i] = s[i+1];
//         // }
//         // s[s.size()-1] = c; 
//         string ans = s.substr(i) + s.substr(0,i);
//         if(ans == s1) return true;
//     }
//     return false;
// }

// Optimal. T.C -> O(n), S.C -> O(n).
bool isRotated(string s,string s1){
    s += s;
    if(s.find(s1) != string::npos){
        return true;
    }
    return false;
}

int main() {
    string s = "paper", s1 = "perpa";
    cout << isRotated(s, s1) << endl;
    return 0;
}