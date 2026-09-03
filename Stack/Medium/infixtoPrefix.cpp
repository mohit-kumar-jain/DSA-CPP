#include<bits/stdc++.h>
using namespace std;
                
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    else if (c == '*' || c == '/') return 2;
    else if (c == '^') return 3;
    else return -1;
}
string infixToPrefix(string s) {
    string res;
    int n = s.size();
    reverse(s.begin(),s.end());
    stack<char> st;
    for(int i = 0; i < n; i++){
        if(s[i] == ')'){
            s[i] = '(';
        }else if (s[i] == '(') {
            s[i] = ')';
        }
    }
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            res += c;
        } else if (c == '('){
            st.push(c);
        } else if (c == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top();
                st.pop();
            }
            st.pop();
        }else{
            while(!st.empty() && st.top() != '(' && precedence(c) < precedence(st.top())){
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
    reverse(res.begin(),res.end());
    return res;
}                   
                   
int main() {
    string s = "a+(b*c)-d";
    cout << "The Infix Expression is : " << s << endl;
    cout << "The Prefix Expression is : " << infixToPrefix(s) << endl;
    return 0;
}