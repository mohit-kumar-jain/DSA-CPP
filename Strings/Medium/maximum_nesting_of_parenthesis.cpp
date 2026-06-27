#include<bits/stdc++.h>      
using namespace std;
             
// Optimal. T.C -> O(n), S.C -> O(1).
int maxNestingCount(string s){
    if(s.size() == 0) return 0;
    int maxcnt = 0, cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '('){
            cnt += 1;
        }else if(s[i] == ')'){
            cnt -= 1;
        }
        maxcnt = max(cnt,maxcnt);
    }
    return maxcnt;
}

int main() {
    string s  = "(1+(2*3)+((8)/4))+1";
    cout << maxNestingCount(s) << endl;
    return 0;
}