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

// Converts Array to double Linked List.
Node* array2DLL(vector<int>& nums){
    if (nums.size() == 0)
    {
       return NULL;
    }
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

// Insertion at begin.
Node* insertAtBegin(Node* head,int val){
    if (head == NULL)
    {
        return new Node(val);
    }
    Node* temp = new Node (val,head,nullptr);
    head -> back = temp;
    head = temp;
    return head;
}

// Insertion at position k of DLL.
Node* insertAtK(Node* head, int val, int k)
{
    if (head == NULL)
        return head;
    if (k == 1)
    {
        Node* temp = new Node(val, head, nullptr);
        head->back = temp;
        return temp;
    }
    int cnt = 1;
    Node* temp = head;
    Node* pre = NULL;
    while (temp && cnt < k)
    {
        pre = temp;
        temp = temp->next;
        cnt++;
    }
    if (temp == NULL)
    {
        if (cnt == k)
        {
            Node* n = new Node(val, nullptr, pre);
            pre->next = n;
        }
        return head;
    }
    Node* n = new Node(val, temp, pre);
    pre->next = n;
    temp->back = n;
    return head;
}

// Insertion of node at given value.
Node* insertAtVal(Node* head,int ele,int val){
    if(head == NULL) return head;
    Node* n = new Node(ele);
    if(head->data == val){
        n -> next = head;
        head -> back = n;
        head = n; 
        return head;
    }
    Node* temp = head;
    while (temp->next)
    {
        if (temp->next->data == val)
        {
            n -> next = temp -> next;
            temp -> next -> back = n;
            temp -> next = n;
            n -> back = temp;
            break;
        }
        temp = temp -> next;
    }
    return head;
}
// Insertion at end.
Node* insertAtEnd(Node* head,int val){
    if (head == NULL)
    {
        Node* n =  new Node(val);
        return n;
    }
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    Node* n = new Node (val,nullptr,temp);
    temp -> next = n;
    return head;
}

// Prints the Double Linked List.
void printDLL(Node* head){
    if(head == NULL) {
        cout << "Empty List!!."<<endl;
        return;
    }
    Node* temp = head;
    while(temp){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1,5,7,9,16,25};
    Node* head = array2DLL(arr);
    printDLL(head);
    head = insertAtVal(head,100,25);
    printDLL(head);
    return 0;
}