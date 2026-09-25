#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

void printLL(Node *head){
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

Node *swapPairs(Node *head)
{
    Node dummy(0, head);
    Node *prev = &dummy, *cur = head;
    while (cur && cur->next)
    {
        Node *npn = cur->next->next;
        Node *second = cur->next;
        second->next = cur;
        cur->next = npn;
        prev->next = second;
        prev = cur;
        cur = npn;
    }
    return dummy.next;
}

int main()
{
    Node* head = new Node(2);
    head->next = new Node(5);
    head->next->next = new Node(51);
    head->next->next->next = new Node(25);
    cout << "Before Swapping Nodes Pairs: ";
    printLL(head);
    Node* res = swapPairs(head);
    cout <<"After Swapping Nodes Pairs: ";
    printLL(res);
    return 0;
}