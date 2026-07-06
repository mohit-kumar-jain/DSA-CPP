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

// Brute. T.C -> O(N), S.C -> O(N).
// bool detectLoop(Node* head){
//     Node* temp = head;
//     unordered_map<Node* , int> mpp;
//     while(temp){
//         if(mpp.find(temp) != mpp.end()){
//             return true;
//         }
//         mpp[temp] = 1;
//         temp = temp->next;
//     }
//     return false;
// }

// Optimal. T.C -> O(N), S.C -> O(1).
bool detectLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}
int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third;
    cout << detectLoop(head) << endl;
    return 0;
}