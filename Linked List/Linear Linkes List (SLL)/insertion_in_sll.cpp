#include<bits/stdc++.h>   
using namespace std;

// Class to create a new Node & constructor to initialize them.
class Node{
    public:
    int data;
    Node* next;
    Node(int data1){
        data = data1;
        next = nullptr;
    }
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }
};

// Convert Array to Linked List.
Node* Array2LL(vector<int>& nums){
    Node* head = new Node(nums[0]);
    Node* mover = head;
    for (int i = 1; i < nums.size(); i++)
    {
        Node* temp = new Node(nums[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

// Print the Linked List.
void printLL(Node* head){
    if(head == NULL) cout << " ";
    Node* temp = head;
    while(temp){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

// Insertion At Begin of the node.
Node* insertHead(Node* head,int val){
    if(head == NULL) {
        head = new Node(val);
    }
    Node* temp = new Node(val,head);
    return temp;
}

// Insertion At position k of the node.
Node* insertAtK(Node* head, int val, int k){
    if(head == NULL) {
        if(k == 1){
            return new Node(val,head);
        }else
            return NULL;
    }
    if(k == 1){
        return new Node(val,head);
    }
    int cnt = 0;
    Node* temp = head;
    while(temp){
        cnt++;
        if(cnt == k - 1){
            Node* n = new Node(val,temp -> next);
            temp -> next = n;
            break;
        }
        temp = temp -> next;
    }
    return head;
}

// Insertion  of the node before the value.
Node* insertBeforeVal(Node* head,int ele,int val){
    if(head == NULL) return NULL;
    if(head -> data == val){
        return new Node(ele,head);
    }
    Node* temp = head;
    while (temp)
    {
        if(temp->next->data == val){
            Node * n = new Node(ele,temp->next);
            temp -> next = n;
            break;
        }
        temp = temp -> next;
    }
    return head;
}

// Insertion At End of the node.
Node* insertTail(Node* head,int val){
    if(head == NULL) {
        return new Node(val);
    }
    Node* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp -> next;
    }
    temp -> next = new Node (val);
    return head;
}

int main() {
    vector<int> nums = {3,6,9,12};
    Node* head = Array2LL(nums);
    head = insertBeforeVal(head,100,12);
    printLL(head);
    return 0;
}