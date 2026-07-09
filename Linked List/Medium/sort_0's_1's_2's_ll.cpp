#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = nullptr;
    }
    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
};

void printLL(Node* head){
    if (head == NULL)cout << " ";
    Node* temp = head;
    while (temp)
    {
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout << endl;
}

// Brute. T.C -> O(2N), S.C -> O(N).
Node* SortLL(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    int cnt0 = 0,cnt1 = 0, cnt2 = 0;
    while (temp)
    {
        if(temp->data == 0) cnt0++;
        else if(temp->data == 1) cnt1++;
        else cnt2++;
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        if(cnt0) {
            temp->data = 0;
            cnt0--;
        }
        else if(cnt1) {
            temp->data = 1;
            cnt1--;
        }
        else {
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
    return head;
}

// Optimal. T.C -> O(N), S.C -> O(1).
// Node* SortLL(Node* head){
//     if(head == NULL || head->next == NULL) return head;
//     Node* temp = head;
//     Node* zeroHead = new Node(-1);
//     Node* oneHead = new Node(-1);
//     Node* twoHead = new Node(-1);
//     Node* zero = zeroHead;
//     Node* one = oneHead;
//     Node* two = twoHead;
//     int cnt0 = 0,cnt1 = 0, cnt2 = 0;
//     while (temp)
//     {
//         if(temp->data == 0) {
//             zero->next = temp;
//             zero = zero->next;
//         }
//         else if(temp->data == 1) {
//             one->next = temp;
//             one  = one->next;
//         }
//         else {
//             two->next = temp;
//             two = two->next;
//         }
//         temp = temp->next;
//     }
//     zero->next = oneHead->next? oneHead->next : twoHead->next;
//     one->next = twoHead->next;
//     two->next = NULL;
//     return zeroHead->next;
//     delete zeroHead;
//     delete oneHead;
//     delete twoHead;
// }

int main() {
    Node* head = new Node(2);
    Node* second = new Node(1);
    Node* third = new Node(0);
    Node* fourth = new Node(0);
    Node* fifth = new Node(1);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    printLL(head);
    Node* res = SortLL(head);
    printLL(res);
    return 0;
}