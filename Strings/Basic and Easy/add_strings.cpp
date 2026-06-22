#include<bits/stdc++.h>       
using namespace std;
// Optimal. T.C -> O(max(n,m)), S.C. -> O(max(m,n)).
string addStrings(string s1, string s2){
    string ans;
    if(s2.size() > s1.size()) return addStrings(s2,s1);
    int i1 = s1.size() - 1 ,i2 = s2.size() - 1 ,carry = 0, sum = 0;
    while(i2 >= 0){
        sum = ((s1[i1] - '0') + (s2[i2] - '0')) + carry;
        carry = sum / 10;
        char c = '0' +  (sum % 10);
        ans += c;
        i2--,i1--;
    }
    while(i1 >= 0){
        sum = (s1[i1] - '0') + carry;
        carry = sum / 10;
        char c = '0' + (sum % 10);
        ans += c;
        i1--;
    }
    if (carry)
    {
        ans += '1';
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    string s1,s2,res;
    s1 = "300",s2 = "256";
    res = addStrings(s1,s2);
    cout << res << endl;
    return 0;
}