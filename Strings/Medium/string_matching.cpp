#include<bits/stdc++.h>
using namespace std;
// Optimal. T.C. -> O(m+n), S.C -> O(m).
void LPS(vector<int>& lps, string s){
    int n = s.size();
    int pre = 0, suf = 1;
    while (suf < n)
    {
        if(s[pre] == s[suf]){
            lps[suf] = pre + 1;
            pre++,suf++;
        }
        else{
            if (pre == 0)
            {
                lps[suf] = 0;
                suf++;
            }else{
                pre = lps[pre-1];
            }
        }
    }
}
int stringMatch(string s,string s1){
    int first = 0, second = 0,n = s.size();
    vector<int> lps(s1.size(),0);
    LPS(lps,s1);
    if(n == 0) return -1;
    while (first < n && second < s1.size())
    {
        if (s[first] == s1[second])
        {
            first++,second++;
        }else{
            if(second == 0){
                first++;
            }else{
                second = lps[second-1];
            }
        }
    }
    if(second == s1.size()){
        return first - second;
    }
    return -1;
}
                   
int main() {
    string s = "abcdefgabcdeabababc";
    string s2 = "cdeabab";
    cout << stringMatch(s,s2) << endl;
    return 0;
}