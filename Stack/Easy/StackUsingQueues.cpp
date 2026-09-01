#include<bits/stdc++.h>
using namespace std;
                   
class Stack{
    queue<int> q;
    public:
        void push(int x) {
            int s = q.size();
            q.push(x);
            for(int i = 0; i < s; i++) {
                q.push(q.front());
                q.pop();
            }
            cout << "Successfully Pushed : "<< x << endl;
        }
        void pop() {
            int n = q.front();
            q.pop();
            cout << "Successfully Poped : "<< n << endl;
        }
        int top(){
            return q.front();
        }
        bool  isEmpty(){
            return q.empty();
        }
};                   
                   
int main() {
    Stack s;
    s.push(10);
    s.push(8);
    s.push(26);
    s.push(79);
    s.pop();
    s.push(69);
    s.pop();
    s.push(450);
    cout << "Stack is Empty? : " << s.isEmpty() << endl;
    cout <<"Top Element is : " <<s.top() << endl;
    s.push(80);
    s.pop();
    cout << "Stack is Empty? : " << s.isEmpty() << endl;
    return 0;
}