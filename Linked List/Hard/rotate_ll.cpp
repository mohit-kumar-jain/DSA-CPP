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
        next = nullptr;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

// Brute. T.C -> O(k*N), S.C ->O(1).
// Node *rotateLL(Node *head, int k)
// {
//     if (head == NULL || head->next == NULL || k == 0)
//         return head;
//     Node *temp = head;
//     int len = 1;
//     for (int i = 0; i < k; i++)
//     {
//         Node *curr = head;
//         Node *prev = NULL;
//         while (curr->next)
//         {
//             prev = curr;
//             curr = curr->next;
//         }
//         prev->next = NULL;
//         curr->next = head;
//         head = curr;
//     }
//     return head;
// }

// Optimal. T.C -> O(2N), S.C -> O(1).
Node *findNthNode(Node *head, int k)
{
    Node *temp = head;
    int len = 1;
    while (temp)
    {
        if (len == k)
            return temp;
        len++;
        temp = temp->next;
    }
    return temp;
}
Node *rotateLL(Node *head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    Node *temp = head;
    int len = 1;
    while (temp->next)
    {
        len++;
        temp = temp->next;
    }
    if (k % len == 0)
        return head;
    k = k % len;
    temp->next = head;
    Node *newLast = findNthNode(head, len - k);
    head = newLast->next;
    newLast->next = NULL;
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

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    printLL(head);
    head = rotateLL(head, 3);
    printLL(head);
    return 0;
}