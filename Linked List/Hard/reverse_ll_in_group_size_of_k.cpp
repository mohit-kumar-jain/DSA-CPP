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
    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
};

Node* reverseLL(Node* head){
    Node* prev = NULL;
    Node* temp = head;
    while(temp){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node* getKthNode(Node* head,int k){
    Node* temp = head;
    k -= 1;
    while(temp && k > 0){
        k--;
        temp = temp->next;
    }
    return temp;
}

// Optimal. T.C -> O(N), S.C -> O(1).
Node* reverseKElements(Node* head,int k){
    Node* temp = head;
    Node* prevLast = NULL;
    while(temp){
        Node* kthNode = getKthNode(temp,k);
        if(kthNode == NULL){
            if(prevLast)  prevLast->next = temp;
            break;
        }
        Node* nextNode = kthNode->next;
        kthNode->next = NULL;
        reverseLL(temp);
        if(temp == head){
            head = kthNode;
        }else{
            prevLast->next = kthNode;
        }
        prevLast = temp;
        temp = nextNode;
    }
    return head;
}

void printLL(Node* head){
    if(head == NULL) cout << " ";
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(5);
    head->next = new Node(7);
    head->next->next = new Node(11);
    head->next->next->next = new Node(17);
    head->next->next->next->next = new Node(56);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(72);
    printLL(head);
    head = reverseKElements(head,3);
    printLL(head);
    return 0;
}