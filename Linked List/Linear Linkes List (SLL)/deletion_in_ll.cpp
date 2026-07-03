#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *Array2LL(vector<int> &nums)
{
    Node *head = new Node(nums[0]);
    Node *mover = head;
    for (int i = 1; i < nums.size(); i++)
    {
        Node *temp = new Node(nums[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(Node *head)
{
    if (head == NULL)
        cout << " ";
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Delete at begining of a LL.
Node *delAtBegin(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return NULL;
    Node *temp = head;
    head = head->next;
    delete (temp);
    return head;
}

// Delete at positionn k of a LL.
Node *delAtK(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (k == 1)
    {
        Node* temp = head;
        head = head -> next;
        delete (temp);
        return head;
    }
    Node *temp = head;
    Node *pre = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        if (cnt == k)
        {
            pre->next = temp->next;
            delete (temp);
            break;
        }
        pre = temp;
        temp = temp->next;
    }
    return head;
}

// Delete at a given value.
Node* delAtVal(Node* head,int val){
    if(head == NULL) return NULL;
    Node* temp = head;
    if(head->data == val){
        temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    Node* pre = head;
    while(temp){
        if(temp -> data == val){
            pre -> next = temp -> next;
            delete temp;
            break;
        }
        pre = temp;
        temp = temp -> next;
    }
    return head;
}

// Delete at ending of a LL.
Node *delAtEnd(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return NULL;
    Node *temp = head;
    Node *pre = head;
    while (temp->next != NULL)
    {
        pre = temp;
        temp = temp->next;
    }
    pre->next = nullptr;
    delete temp;
    return head;
}

int main()
{
    vector<int> arr = {10, 25, 36, 78};
    Node *head = Array2LL(arr);
    printLL(head);
    head = delAtVal(head, 10);
    printLL(head);
    return 0;
}