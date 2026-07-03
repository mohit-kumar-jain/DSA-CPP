#include<bits/stdc++.h>
using namespace std;
        
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
    Node(int data1, Node* next1,Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
};

int main() {
    vector<int> arr = {1,2,3,4,5};
    Node* y = new Node(arr[3]);
    cout << y << endl;
    cout << y->data << endl;
    return 0;
}