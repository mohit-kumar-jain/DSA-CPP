#include<bits/stdc++.h>
using namespace std;
                

string postfixToPrefix(string s) {
    string res;
    int n = s.size();
    stack<string> st;
    for (int i = 0; i < n; i++)
    {
        char c =  s[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') ){
            st.push(string(1,c));
        } else {
            string b = st.top();
            st.pop();
            string a = st.top();
            st.pop();
            string r =  c + a + b ;
            st.push(r);
        }
    }
    return st.top();
}                   
                   
int main() {
    string s = "ab+c*";
    cout << "The Postfix Expression is : " << s << endl;
    cout << "The Prefix Expression is : " << postfixToPrefix(s) << endl;
    return 0;
}