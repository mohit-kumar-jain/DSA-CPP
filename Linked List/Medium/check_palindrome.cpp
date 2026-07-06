#include<bits/stdc++.h>                  
using namespace std;
    
class Node {
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

// Brute. T.C -> O(N), S.C -> O(N).
// bool checkPalindrome(Node* head){
//     Node* temp = head;
//     stack<int> st;
//     while(temp){
//         st.push(temp->data);
//         temp = temp->next;
//     }
//     temp = head;
//     while(temp && !st.empty()){
//         if(temp->data != st.top()){
//             return false;
//         }else{
//             st.pop();
//             temp = temp->next;
//         }
//     }
//     return true;
// }

// Optimal. T.C -> O(N), S.C -> O(1).
Node* reverseLinkedList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head; 
    }
    Node* newHead = reverseLinkedList(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

bool checkPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    Node* slow = head;
    Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = reverseLinkedList(slow->next);
    Node* first = head;
    Node* second = newHead;
    while (second != NULL) {
        if (first->data != second->data) {
            reverseLinkedList(newHead);
            return false;
        }

        first = first->next;
        second = second->next; 
    }
    reverseLinkedList(newHead);
    return true;
}


int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(2);
    Node* fifth = new Node(1);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    cout << checkPalindrome(head);
    return 0;
}