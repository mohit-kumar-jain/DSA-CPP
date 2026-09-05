#include<bits/stdc++.h>
using namespace std;
                   
string prefixToPostfix(string s) {
    int n = s.size();
    stack<string> st;
    for (int i = n-1; i >= 0; i--)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
            st.push(string(1,s[i]));
        }else{
            string b = st.top();
            st.pop();
            string a = st.top();
            st.pop();
            string res =  b + a + s[i];
            st.push(res);
        }
    }
    return st.top();
}                   
                   
int main() {
    string s = "*+abc";
    cout << "The Prefix Expression is : " << s << endl;
    cout << "The Postfix Expression is : " << prefixToPostfix(s) << endl;
    return 0;
}