#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *random;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
        random = nullptr;
    }
    Node(int data, Node *next,Node* random)
    {
        this->data = data;
        this->next = next;
        this->random = random;
    }
};

// Brute. T.C -> O(2N),S.C -> O(N)+O(N).
// Node* CloneLL(Node* head) {
//     if(head == NULL) return NULL;
//     Node* temp = head;
//     unordered_map<Node*,Node*> mpp;
//     while (temp)
//     {
//         Node* newNode = new Node(temp->data);
//         mpp[temp] = newNode;
//         temp = temp->next;
//     }
//     temp = head;
//     Node* copyNode = head;
//     while(temp){
//         copyNode = mpp[temp];
//         copyNode->next = mpp[temp->next];
//         copyNode->random = mpp[temp->random];
//         temp = temp->next;
//     }
//     return mpp[head];
// }

// Optimal. T.C -> O(3N),S.C ->O(N).
Node* CloneLL(Node* head){
    Node* temp = head;
    Node* copyNode;
    while(temp){
        copyNode = new Node(temp->data);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = temp->next->next;
    }
    
    temp = head;
    while(temp){
        copyNode = temp->next;
        if(temp->random) 
            copyNode->random = temp->random->next;
        else 
            copyNode->random = nullptr;
        temp = temp->next->next;
    }

    temp = head;
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    while(temp){
        res->next = temp->next;
        temp->next = temp->next->next;

        res = res->next;
        temp = temp->next;
    }
    return dummyNode->next;
}
void printLL(Node* head){
    if(head == 0) cout << " ";
    Node* temp = head;
    while(temp){
        cout << "Data: " << temp->data << " ";
        if (temp->random != nullptr) {
            cout << ", Random: " << temp->random->data << ". ";
        } else {
            cout << ", Random: nullptr";
        }
        temp = temp->next;
    }
    cout << endl;
}
                   
int main() {
    Node* head = new Node(5);
    head->next = new Node(9);
    head->next->next = new Node(7);
    head->next->next->next = new Node(8);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;
    printLL(head);
    head = CloneLL(head);
    printLL(head);
    return 0;
}