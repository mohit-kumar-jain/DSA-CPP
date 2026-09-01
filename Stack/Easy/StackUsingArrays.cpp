#include <bits/stdc++.h>
using namespace std;

class Stack {

private:
    int topIndex = -1;
    int size;
    int arr[10];
    
    public:
    
    Stack() {
        size = 10;
    }

    void push(int x) {

        if(topIndex >= size - 1) {
            cout << "Stack is Full!. Cannot Push." << endl;
        }
        else {
            topIndex++;
            arr[topIndex] = x;

            cout << "Successfully Pushed : " << x << endl;
        }
    }

    void pop() {

        if(topIndex == -1) {
            cout << "Stack is Empty!. Cannot Pop." << endl;
        }
        else {
            int ele = arr[topIndex];
            topIndex--;

            cout << "Successfully Deleted : " << ele << endl;
        }
    }

    int top() {

        if(topIndex == -1) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }

        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == size - 1;
    }
};

int main() {

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.pop();
    s.pop();

    s.push(45);

    cout << "Top element: " << s.top() << endl;

    cout << "Is Empty: " << boolalpha << s.isEmpty() << endl;

    cout << "Is Full: " << boolalpha << s.isFull() << endl;

    return 0;
}