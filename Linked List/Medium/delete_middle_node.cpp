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

// Brue. T.C -> O(N+(N/2)), S.C -> O(1).
// Node *deleteMiddle(Node *head)
// {
//     Node *temp = head;
//     int n = 0;
//     while (temp != NULL)
//     {
//         n++;
//         temp = temp->next;
//     }
//     int res = n / 2;
//     temp = head;
//     while (temp != NULL)
//     {
//         res--;
//         if (res == 0)
//         {
//             Node *middle = temp->next;
//             temp->next = temp->next->next;
//             delete (middle);
//             break;
//         }
//         temp = temp->next;
//     }
//     return head;
// }

// Optimal. T.C -> O(N/2), S.C -> O(1).
Node *deleteMiddle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;
    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;
    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(15);
    printLL(head);
    head = deleteMiddle(head);
    printLL(head);
    return 0;
}