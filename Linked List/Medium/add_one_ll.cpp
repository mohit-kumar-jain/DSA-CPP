#include<iostream>
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

Node* reverseLL(Node* head){
    Node* temp = head;
    Node* prev = NULL;
    while(temp){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

void printLL(Node* head){
    if(head == NULL) cout <<" ";
    Node* temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Optimal. T.C -> O(N), S.C -> O(1). (Using Iteration)
// Node* addOne(Node* head){
//     if(head == nullptr) return new Node(1);
//     head = reverseLL(head);
//     Node* temp = head;
//     int carry = 1;
//     while(temp){
//         if(temp->data + carry < 10){
//             temp->data = temp->data + carry;
//             carry = 0;
//             head = reverseLL(head);
//             return head;
//         }else{
//             temp->data = (temp->data + carry) % 10;
//             carry = 1;
//         }
//         if(temp->next == NULL) break;
//         temp = temp->next;
//     }
//     if(carry){
//         Node* newNode = new Node(1);
//         newNode->next = head;
//         head = newNode;
//         return head;
//     }
//     head = reverseLL(head);
//     return head;
// }

// Optimal. T.C -> O(N), S.C -> O(N). (Using Recursion)
int helper(Node* head){
    Node* temp = head;
    if(temp == NULL) return 1;
    int carry = helper(temp->next);
    int sum = temp->data+carry;
    temp->data = sum % 10;
    return sum / 10;
}

Node* addOne(Node* head){
    if(head == nullptr) return new Node(1);
    int carry = helper(head);
    if(carry){
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

int main() {
    Node* head = new Node(9); 
    Node* sec = new Node(9); 
    Node* thi = new Node(9); 
    Node* fou = new Node(9); 
    Node* fif = new Node(9); 
    head->next = sec;
    sec->next = thi;
    thi->next = fou;
    fou->next = fif;
    printLL(head);
    head = addOne(head);
    printLL(head);
    return 0;
}