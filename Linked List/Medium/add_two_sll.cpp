#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL; 
    }
    Node(int data,Node* next){
        this->data = data;
        this->next = next; 
    }
};

Node* addLL(Node* head1, Node* head2){
    Node* dummy = new Node(-1);
    Node* curr = dummy;
    Node* t1 = head1;
    Node* t2 = head2;
    int carry = 0;
    while(t1 || t2){
        int sum = carry;
        if(t1) sum += t1->data;
        if(t2) sum += t2->data;
        sum += carry;
        carry = sum / 10;
        Node* temp = new Node(sum %10);
        curr -> next = temp;
        curr = curr->next;
        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
    }
    if(carry){
        Node* temp = new Node(carry);
        curr -> next = temp;
    }
    return dummy -> next;
}

Node* createList(vector<int> nums){
    if(nums.size() == 0) return NULL;
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

void printLL(Node* head){
    Node* temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    vector<int> num1 = {2, 4, 3}; // represents 342
    vector<int> num2 = {5, 6, 4}; // represents 465
    Node* l1 = createList(num1);
    Node* l2 = createList(num2);
    Node* result = addLL(l1,l2);
    printLL(result);
    return 0;
}