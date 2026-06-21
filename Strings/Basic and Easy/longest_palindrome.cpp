#include<bits/stdc++.h>
using namespace std;

//  Optimal. T.C. -> O(N), S.C. -> O(1).
int longestPalindrome(string s){
    vector<int>lower (26,0);
    vector<int>upper (26,0);
    for(int i = 0; i < s.size();i++){
        if(s[i] >= 'a'){
            lower[s[i] - 'a']++;
        }else{
            upper[s[i] - 'A']++;
        }
    }
    int cnt = 0;
    bool odd = 0;
    for(int i = 0; i < 26;  i++){
        cnt += (lower[i]/2) * 2;
        cnt += (upper[i]/2) * 2;
        if(lower[i] % 2 || upper[i] % 2){
            odd = 1;
        }
    }
    return cnt + odd;
}

int main(){
    string s = "abccccddAABBC";
    cout<<longestPalindrome(s)<<endl;
    return 0;
}