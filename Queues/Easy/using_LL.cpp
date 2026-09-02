#include<bits/stdc++.h>
using namespace std;

class QueueUsingLL{
    private:
        class Node{
            public:
                int data;
                Node* next;
                Node(int x) {
                    this->data = x;
                    this->next = NULL;
                }
        };
        Node *start, *end;
        int size;
    public:
        QueueUsingLL() {
            start = end = nullptr;
            size = 0;
        }
        void push(int x) {
            Node* temp = new Node(x);
            if(start == NULL){
                start = end = temp;
            }else{
                end->next = temp;
                end = temp;
            }
            size++;
            cout << "Successfully Pushed : " << x << endl;
        }
        void pop() {
            if(start == NULL) {
                cout << "Queue is Empty. Cannot Dequeue." << endl;
                return;
            }
            else if(start == end) {
                start = end  = nullptr;
                size--;
            }else{ 
                int ele = start->data;
                Node * temp = start;
                start = start->next;
                delete temp;
                cout << "Successfully Popped : " << ele << endl;
                size--;
            }
        }
        void top() {
            if(end == NULL) {
                cout << "Queue is Empty." << endl;
                return;
            } else{
                cout << "The top element of Queue is : " << start->data << endl;
            }
        }
        void Size() {
            cout << "The size of the Queue is : " << size << endl;
        }
};                   
                   
int main() {
    QueueUsingLL q;
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