#include<bits/stdc++.h>
using namespace std;
                   
string removeDigits(string num, int k) {
    string res = "";
    stack<char> st;
    for (int i = 0; i < num.size(); i++)
    {
        while(!st.empty() && k > 0 && st.top() > num[i]){
            st.pop();
            k -= 1;
        }
        st.push(num[i]);
    }
    while(!st.empty() && k > 0) {
        st.pop();
    }
    if(st.empty()) return "0";
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    while(res.size() > 0 && res.back() == '0'){
        res.pop_back();
    }
    reverse(res.begin(), res.end());
    if(res.empty()) return "0";
    return res;
}                   
                   
int main() {
    string nums = "541892";
    int k = 2;
    cout << removeDigits(nums,k) << endl;
    return 0;
}