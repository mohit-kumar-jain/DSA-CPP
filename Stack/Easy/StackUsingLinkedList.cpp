#include<bits/stdc++.h>
using namespace std;
                   
class Stack{
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
        Node* topIndex = NULL;
    public:
        void push(int x) {
            Node* ele = new Node(x);
            ele->next = topIndex;
            topIndex = ele;
            cout << "Successfully Pushed : "<< x << endl;
        }
        void pop() {
            if(topIndex == NULL) {
                cout << "Stack is Empty!. Cannot Pop." << endl;
                return;
            }
            Node * temp = topIndex;
            int ele = temp->data;
            topIndex = topIndex->next;
            delete temp;
            cout << "Successfully Deleted : "<< ele << endl;
        }
        int top() {
            if(topIndex == NULL) {
                cout << "Stack is Empty!" << endl;
                return -1;
            }
            return topIndex->data;
        }
        bool isEmpty() {
            return topIndex == NULL;
        }
};                   
                   
int main() {
    Stack s;
    s.push(5);
    s.push(52);
    s.push(56);
    s.pop();
    s.push(45);
    s.pop();
    s.push(15);
    s.isEmpty();
    return 0;
}