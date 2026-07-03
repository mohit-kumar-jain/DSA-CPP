#include<bits/stdc++.h>   
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data1){
        data = data1;
        next = nullptr;
    }
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }
};

Node* Array2LL(vector<int>& nums){
    Node* head = new Node(nums[0]);
    Node* mover = head;
    for (int i = 1; i < nums.size(); i++)
    {
        Node* temp = new Node(nums[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

void printLL(Node* head){
    if(head == NULL) cout << " ";
    Node* temp = head;
    while(temp){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

// Brute. T.C -> O(n+(n/2)),S.C -> O(1);
// Node* findMiddle(Node *head) {
//     if (head == NULL || head->next == NULL) {
//         return head;
//     }
//     Node* temp = head;
//     int count = 0;
//     while (temp != NULL) {
//         count++;
//         temp = temp->next;
//     }
//     int mid = count / 2 + 1;
//     temp = head;
//     while (temp != NULL) {
//         mid = mid - 1;
//         if (mid == 0){
//             break;
//         }
//         temp = temp->next;
//     }
//     return temp;
// }
    
// Optimal. T.C -> O(n/2),S.C -> O(1).
Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

int main() {
    vector<int>nums= {1,2,3,4,5,6};
    Node* head = Array2LL(nums);
    printLL(head);
    head =  findMiddle(head);
    cout << head->data << endl;
    return 0;
}