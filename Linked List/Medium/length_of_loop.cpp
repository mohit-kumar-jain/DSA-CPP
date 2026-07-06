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
// int detectLengthLoop(Node* head){
//     Node* temp = head;
//     unordered_map<Node* , int> mpp;
//     int len = 0;
//     while(temp){
//         if(mpp.find(temp) != mpp.end()){
//             return len - mpp[temp];
//         }
//         mpp[temp] = len;
//         temp = temp->next;
//         len++;
//     }
//     return len;
// }

// Optimal. T.C -> O(N), S.C -> O(1).
int detectLengthLoop(Node* head){
    Node* slow = head;
    Node* fast = head;
    int len = 0;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        len++;
        if(slow == fast) {
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
                return len;
            }
        }
    }
    return len;
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
    cout << detectLengthLoop(head) << endl;
    return 0;
}