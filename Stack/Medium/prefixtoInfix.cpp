#include<bits/stdc++.h>
using namespace std;
                
string prefixToInfix(string s) {
    int n = s.size();
    stack<string> st;
    for (int i = n-1; i >= 0; i--)
    {
        char c =  s[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') ){
            st.push(string(1,c));
        }else{
            string b = st.top();
            st.pop();
            string a = st.top();
            st.pop();
            string res = "(" + b + c + a + ")";
            st.push(res);
        }
    }
    return st.top();
}                   
                   
int main() {
    string s = "*+ab-cd";
    cout << "The Prefix Expression is : " << s << endl;
    cout << "The Infix Expression is : " << prefixToInfix(s) << endl;
    return 0;
}