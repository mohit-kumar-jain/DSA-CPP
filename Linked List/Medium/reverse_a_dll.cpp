#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;
    Node(int data){
        this->data = data;
        next = nullptr;
        back = nullptr;
    }
    Node(int data,Node* next,Node* back){
        this->data = data;
        this->next = next;
        this->back = back;
    }
};

Node* vecToDll(vector<int>& nums) {
    if(nums.size() == 0) return NULL;
    Node* head = new Node(nums[0]);
    Node* mover = head;
    for (int i = 1; i < nums.size(); i++)
    {
        Node* temp = new Node(nums[i]);
        mover->next = temp;
        temp->back = mover;
        mover = temp;
    }
    return head;
};
 
void printDLL(Node* head) {
    Node* temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverseDLL(Node* head) {
    if(head == NULL || head->next == NULL)  return head;
    Node* prev = NULL;
    Node* curr = head;
    while(curr) {
        Node* temp = curr -> next;
        curr->next = curr->back;
        curr->back = temp;
        head = curr;
        curr = temp;
    }
    return head;
}

int main() {
    vector<int> n = {1,0,5};
    Node* l1 = vecToDll(n);
    printDLL(l1);
    l1 = reverseDLL(l1);
    printDLL(l1);
    return 0;
}