#include<bits/stdc++.h>       
using namespace std;
     
class Node{
    public:
    int data;
    Node* next;
    Node(int data1){
        data = data1;
        next = nullptr;
    }
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
};

Node* Array2LL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void Traversal(Node* head){
    if(head == NULL) cout << "";
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp -> next;
    }
}

int main() {
    vector<int> arr = {100,2,3,4,5};
    Node* head =  Array2LL(arr);
    Traversal(head);
    return 0;
}