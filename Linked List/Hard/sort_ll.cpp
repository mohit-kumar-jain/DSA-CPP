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
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Brute. T.C -> O(2N + (N*logn)), S.C -> O(N).
// Node* sortLL(Node* head){
//     vector<int> nums;
//     Node* temp = head;
//     while(temp){
//         nums.push_back(temp->data);
//         temp = temp->next;
//     }
//     sort(nums.begin(),nums.end());
//     temp = head;
//     int i = 0;
//     while(temp){
//         temp ->data = nums[i];
//         i++;
//         temp = temp->next;
//     }
//     return head;
// }

// Optimal. T.C -> O(N*(logn)), S.C -> O(1).
Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeList(Node* left, Node* right){
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(left && right){
        if(left->data <= right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    if(left) temp->next = left;
    else temp->next = right;
    return dummyNode->next;
}

Node* sortLL(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* midd = findMid(head);
    Node* right = midd->next;
    midd->next = nullptr;
    Node* left = head;
    left = sortLL(left);
    right = sortLL(right);
    return mergeList(left,right);
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(25);
    head->next->next = new Node(5);
    head->next->next->next = new Node(69);
    head->next->next->next->next = new Node(14);
    printLL(head);
    sortLL(head);
    printLL(head);
    return 0;
}