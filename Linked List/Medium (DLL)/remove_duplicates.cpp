#include<bits/stdc++.h>               
using namespace std;
              
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data = data;
        prev = NULL;
        next = NULL;
    }
    Node(int data,Node* prev ,Node* next = nullptr){
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

void printDLL(Node* head){
    if(head == NULL) cout << " ";
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Optimal. T.C -> O(N), S.C -> O(1).
Node* removeDuplicates(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    while (temp && temp->next)
    {
        Node* nextNode = temp->next;
        while(nextNode && temp->data == nextNode->data){
            Node* duplicate = nextNode;
            nextNode = nextNode->next;
            delete duplicate;
        }
        temp->next = nextNode;
        if(nextNode) nextNode->prev = temp;
        temp = temp->next;
    }
    return head;
}

int main() {
    Node* head = new Node(1);
    Node* first = new Node(1,head);
    Node* second = new Node(3,first);
    Node* third = new Node(4,second);
    Node* fourth = new Node(5,third);
    Node* fifth = new Node(5,fourth);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    printDLL(head);
    head = removeDuplicates(head);
    printDLL(head);
    return 0;
}