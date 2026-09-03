#include<bits/stdc++.h>
using namespace std;
                
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    else if (c == '*' || c == '/') return 2;
    else if (c == '^') return 3;
    else return -1;
}
string infixToPost(string s) {
    string res;
    int n = s.size();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        char c =  s[i];
        if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9') {
            res += c;
        } else if(c == '(') {
            st.push('(');
        } else if (c == ')') {
            while(st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        } else{
            while(!st.empty() && precedence(s[i]) <= precedence(st.top())){
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}                   
                   
int main() {
    string s = "a+(b*c)-d";
    cout << "The Infix Expression is : " << s << endl;
    cout << "The Postfix Expression is : " << infixToPost(s) << endl;
    return 0;
}