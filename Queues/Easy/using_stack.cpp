#include<bits/stdc++.h>
using namespace std;
                   
class QueueUsingStack{
    stack<int> st1,st2;
    public:
    QueueUsingStack() {}
    void push(int x) {
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        cout << "Successfully Pushed : " << x << endl;
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    void pop() {
        if(st1.empty()) cout << "Queue is Empty. Cannot Dequeue." << endl;
        int ele = st1.top();
        st1.pop();
        cout << "Successfully Deleted : " << ele << endl;
    }
    void top(){
        if(st1.empty()) cout << "Queue is Empty!!." << endl;
        else cout << "The Top Element of the Queue is : " << st1.top() << endl;
    }
    void size() {
        cout << "The size of the Queue is : " << st1.size() << endl;
    }
};                   
                   
int main() {
    QueueUsingStack q;
    q.push(5);
    q.push(78);
    q.push(569);
    q.top();
    q.push(45);
    q.pop();
    q.size();
    q.push(7);
    q.pop();
    q.pop();
    q.size();
    q.push(145);
    q.top();
    q.size();
    return 0;
}