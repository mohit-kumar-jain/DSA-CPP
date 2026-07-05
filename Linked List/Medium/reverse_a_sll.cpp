#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};

Node *Array2LL(vector<int> &nums){
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

// Brute. T.C -> O(N), S.C -> O(N).
// Node *reverseLL(Node *head)
// {
//     stack<int> st;
//     Node *temp = head;
//     while (temp)
//     {
//         st.push(temp->data);
//         temp = temp->next;
//     }
//     temp = head;
//     while(temp){
//         temp -> data = st.top();
//         st.pop();
//         temp = temp -> next;
//     }
//     return head;
// }

// Better. T.C -> O(N), S.C -> O(1). (Using Iteration).
// Node *reverseLL(Node *head){
//     Node* temp = head;
//     Node* prev = NULL;
//     while (temp)
//     {
//         Node* front = temp -> next;
//         temp -> next = prev;
//         prev = temp;
//         temp = front;
//     }
//     return prev;
// }

// 2. Better. T.C -> O(N), S.C -> O(N). (Using recursion).
Node *reverseLL(Node *head){
    if(head == NULL || head -> next == NULL) return head;
    Node* rev = reverseLL(head -> next);
    Node* front  = head -> next;
    front -> next = head;
    head -> next = NULL;
    return rev;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    Node *head = Array2LL(nums);
    printLL(head);
    head = reverseLL(head);
    printLL(head);
    return 0;
}