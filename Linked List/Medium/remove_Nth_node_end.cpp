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
    Node(int data,Node* next){
        this->data = data;
        this->next = next;
    }
};

void printLL(Node* head){
    if(head == NULL) cout << " ";
    Node* temp = head;
    while(temp){
        cout << temp->data<< " ";
        temp = temp->next;
    }
    cout << endl;
}

// Brue. T.C -> O(L)+ O(L-N), S.C -> O(1).
// Node* deleteNthFromEnd(Node* head,int n){
//     if(head == NULL) return NULL;
//     int cnt = 0;
//     Node* temp = head;
//     while(temp){
//         cnt++;
//         temp =temp->next;
//     }
//     if(cnt == n){
//         Node* temp = head;
//         head = head->next;
//         delete temp;
//         return head;
//     }
//     temp = head;
//     int res = cnt - n;
//     while(temp){
//         res--;
//         if(res == 0){
//             break;
//         }
//         temp = temp->next;
//     } 
//     Node* delNode = temp->next;
//     temp -> next = temp->next->next;
//     delete delNode;
//     return head;
// }

// Optimal. T.C -> O(N), S.C -> O(1).
Node* deleteNthFromEnd(Node* head, int n){
    Node* slow = head;
    Node* fast = head;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    if(fast == NULL){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    Node* delNoode = slow ->next;
    slow->next = slow->next->next;
    delete delNoode;
    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    printLL(head);
    int N = 1;
    head = deleteNthFromEnd(head,N);
    printLL(head);
    return 0;
}