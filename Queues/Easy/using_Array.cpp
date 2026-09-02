#include<bits/stdc++.h>
using namespace std;
                   
class QueueUsingArray{
    public:
        int start = -1, end = -1, currSize = 0, size = 10;
        int q[10];
        void push(int x) {
            if(currSize == size) {
                cout << "Queue is Full. Cannot Push." << endl;
                return;
            }
            if(currSize == 0) {
                start = end = 0;
            } else  {
                end = (end + 1) % size;
            }
            q[end] = x;
            cout << "Successfully Pushed : " << x << endl;
            currSize++;
        }
        void pop() {
            if(currSize == 0) {
                cout << "Cannot pop. Queue is Empty." << endl;
                return;
            } 
            int ele = q[start];
            if(start == end) {
                start = end = -1;
            } else {
                start = (start + 1 ) % size; 
            }
            currSize--;
            cout << "Successfully Poped : " << ele << endl;
        }
        void top() {
            if(currSize == 0) {
                cout << "Queue is Empty." << endl;
                return;
            }else{
                cout << "The Top element of Queue is : "<< q[start] << endl;
            }
        }
        void Size() {
            cout << "The size of the Queue is : " << currSize << endl;
        }

};                   
                   
int main() {
    QueueUsingArray q;
    q.push(5);
    q.push(78);
    q.push(569);
    q.top();
    q.push(45);
    q.pop();
    q.Size();
    q.push(7);
    q.pop();
    q.pop();
    q.Size();
    q.push(145);
    q.top();
    q.Size();
    return 0;
}