#include<bits/stdc++.h>
using namespace std;

// Optimal. T.C -> O(N*N), S.C -> O(N).
void insertBottomStack(stack<int> &s,int data){
    if(s.empty()){
        s.push(data);
        return;
    }
    int topval = s.top();
    s.pop();
    insertBottomStack(s,data);
    s.push(topval);
}       

void reverseStack(stack<int>& s){
    if(s.empty()) return;
    int val = s.top();
    s.pop();
    reverseStack(s);
    insertBottomStack(s,val);
}

int main() {
    stack<int> s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    stack<int> x = s;
    while (!x.empty())
    {
        cout << x.top()<<" ";
        x.pop();
    }
    cout << endl;
    reverseStack(s);
    while (!s.empty())
    {
        cout << s.top() <<" ";
        s.pop();
    }
    cout << endl;
    return 0;
}