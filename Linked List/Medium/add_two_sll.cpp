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
    Node* res;

    return res;
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