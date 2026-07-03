#include<bits/stdc++.h>        
using namespace std;

struct Node
{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
    Node(int data1, Node*next1, Node*back1){
        data = data1;
        next = next1;
        back = back1;
    }
};

Node* array2DLL(vector<int>& nums){
    if(nums.size() == 0) return NULL;
    Node* temp = new Node(nums[0]);
    Node* pre = temp;
    for (int i = 1; i < nums.size(); i++)
    {
        Node* n = new Node(nums[i],nullptr,pre);
        pre -> next = n;
        pre = n;
    }
    return temp;
}

// Delete at Begin in a DLL.
Node* delAtBeg(Node* head){
    if(head == NULL)    return head;
    if(head -> next == NULL) {
        Node* temp = head;
        head = NULL;
        delete temp;
        return head;
    }
    Node* temp = head;
    head = temp -> next;
    delete temp;
    head -> back = nullptr;
    return head;
}

// Delete at Ending in a DLL.
Node* delAtEnd(Node* head){
    if(head == NULL) return head;
    if(head-> next == NULL) return NULL;
    Node* temp = head;
    Node* pre = head;
    while(temp->next != NULL){
        pre = temp;
        temp = temp-> next;
    }
    delete temp;
    pre -> next = NULL;
    return head;
}

// Delete at Kth position of a node.
Node* delAtK(Node* head,int k){
    if(head == NULL) return NULL;
    if(k == 1){
        Node* temp  = head;
        head = temp -> next;
        if (head)  head -> back = NULL;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    int cnt = 1;
    while (temp != NULL)
    {
        if(cnt == k){
            prev -> next = temp -> next;
            if(temp -> next != NULL){
                temp -> next -> back = prev;
            }
            delete temp;
            break;
        }
        cnt += 1;
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

// Delete node at given value;
Node* delAtVal(Node* head,int val){
    if(head == NULL) return head;
    if(head -> data == val) {
        Node* temp = head;
        head = head -> next;
        if(head) head->back = NULL; 
        delete temp;
        return head;
    }
    Node* temp = head;
    while(temp){
        if(temp-> data == val){
            temp -> back -> next = temp -> next;
            if(temp -> next)
                temp -> next -> back = temp -> back; 
            delete temp;
            break;
        }
        temp = temp -> next;
    }
    return head;
}

void printDLL(Node* head){
    if(head == NULL){
        cout << " " << endl;
    }
    Node* temp = head;
    while(temp){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1,2,3,4,5,6};
    Node* head = array2DLL(arr);
    printDLL(head);
    head = delAtVal(head,6);
    printDLL(head);
    return 0;
}