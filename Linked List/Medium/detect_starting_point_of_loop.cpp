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
// Node* detectLoop(Node* head){
//     Node* temp = head;
//     unordered_map<Node* , int> mpp;
//     while(temp){
//         if(mpp.find(temp) != mpp.end()){
//             return temp;
//         }
//         mpp[temp]++;
//         temp = temp->next;
//     }
//     return NULL;
// }

// Optimal. T.C -> O(N), S.C -> O(1).
Node* detectLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
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
    Node* res = detectLoop(head);
    cout << res->data << endl;
    return 0;
}