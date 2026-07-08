#include<bits/stdc++.h>                   
using namespace std;
    
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = nullptr;
    }
    Node(int data,Node* next){
        this->data = data;
        this->next = next;
    }
};

Node* head, * tail ,* newNode;
void insertAtEnd(int data){
    newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        tail = tail->next;
    }
}

void printLL(Node* head){
    if(head == NULL) cout << " ";
    Node* temp = head;
    while(temp){
        cout << temp->data<< " ";
        temp = temp->next;
    }
    cout << endl;
}

// Brue. T.C -> O(N), S.C -> O(N).
// Node* segregateNode(Node* head){
//     if(head && head->next) return head;
//     vector<int> data;
//     Node* temp = head;
//     while (temp && temp->next)
//     {
//         data.push_back(temp->data);
//         temp = temp->next->next;
//     }
//     if(temp) data.push_back(temp->data);
//     temp = head -> next;
//     while (temp && temp->next)
//     {
//         data.push_back(temp->data);
//         temp = temp->next->next;
//     }
//     if(temp) data.push_back(temp->data);
//     int i = 0;
//     temp = head;
//     while (temp && i < data.size())
//     {
//         (temp->data) = data[i];
//         temp = temp->next;
//         i++;
//     }
//     return head;
// }

// Optimal. T.C -> O(N), S.C -> O(1).
Node* segregateNode(Node* head){
    if(head && head->next) return head;
    Node* odd = head,* even  = head -> next, *evenhead = head->next;
    while (even && even->next)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenhead;
    return head;
}

int main() {
    insertAtEnd(5);
    insertAtEnd(7);
    insertAtEnd(2);
    insertAtEnd(4);
    printLL(head);
    segregateNode(head);
    printLL(head);
    return 0;
}