#include<bits/stdc++.h>
using namespace std;
        
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
    Node(int data1, Node* next1,Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
};

Node* array2DLL(vector<int>& nums){
    Node* head = new Node(nums[0]);
    Node* pre = head;
    for (int i = 1; i < nums.size(); i++)
    {
        Node* temp = new Node(nums[i],nullptr,pre);
        pre -> next = temp;
        pre = temp;
    }
    return head;
}

void printDLL(Node* head){
    if(head == NULL) cout <<" ";
    Node* temp = head;
    while(temp){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    Node* head = array2DLL(arr);
    printDLL(head);
    return 0;
}