#include<bits/stdc++.h>
using namespace std;
bool isValidParenthesis(string s) {
    stack<int> st;
    for(char ch: s){
        if(ch == '(' || ch == '[' || ch == '{'){
            st.push(ch);
        }else{
            if(st.empty()) return false;
            char top = st.top();
            st.pop();
            if(ch == ')' && top != '(') return false;
            if(ch == '}' && top != '{') return false;
            if(ch == ']' && top != '[') return false;
        }
    }
    return st.empty();
}

int main(){
    string s = "(()(({{}})))";
    cout << (isValidParenthesis(s)? "True" :  "False");
    return 0;
}