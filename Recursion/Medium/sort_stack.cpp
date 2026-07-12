#include<bits/stdc++.h>
using namespace std;

void insertStack(stack<int>& s, int temp){
    if(s.empty() || s.top() <= temp){
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insertStack(s,temp);
    s.push(val);
}

//T.C -> O(N*N), S.C -> O(N). 
void sortStack(stack<int>& s) {
if(!s.empty()){
        int temp = s.top();
        s.pop();
        sortStack(s);
        insertStack(s,temp);
    }
}

int main() {
    stack <int> s;
    s.push(5);
    s.push(1);
    s.push(2);
    s.push(7);
    s.push(6);
    stack<int> x = s;
    while (!x.empty())
    {
        cout << x.top() <<" ";
        x.pop();
    }
    cout << endl;
    sortStack(s);
    while (!s.empty())
    {
        cout << s.top() <<" ";
        s.pop();
    }
   return 0;
}