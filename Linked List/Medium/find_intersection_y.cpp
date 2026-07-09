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

// Brute. T.C -> O(N1*N2), S.C -> O(N).
// Node* checkIntersection(Node* head1,Node* head2){
//     while(head2){
//         Node* temp = head1;
//         while(temp){
//             if(temp == head2){
//                 return head2;
//             }
//             temp = temp->next;
//         }
//         head2 = head2->next;
//     }
//     return NULL;
// }

// Better. T.C -> O(N1+N2), S.C -> O(N).
// Node* checkIntersection(Node* head1,Node* head2){
//     unordered_map<Node*,int> mpp;
//     Node* temp = head1;
//     while(temp){
//         mpp[temp]++;
//         temp = temp->next;
//     }
//     temp = head2;
//     while(temp){
//         if(mpp.find(temp) != mpp.end()) return temp;
//         temp = temp->next;
//     }
//     return NULL;
// }

// 1.Optimal. T.C -> O(N1+2N2), S.C -> O(1).
// int getDifference(Node* head1, Node* head2){
//     Node* temp1 = head1;
//     Node* temp2 = head2;
//     int len1 = 0,len2 = 0;
//     while(temp1){
//         len1++;
//         temp1 = temp1->next;
//     }
//     while(temp2){
//         len2++;
//         temp2 = temp2->next;
//     }
//     return len1-len2;
// }

// Node* checkIntersection(Node* head1,Node* head2){
//     int diff = getDifference(head1,head2);
//     if(diff < 0) {
//         while(diff != 0){
//             head2 = head2->next;
//             diff++;
//         }
//     }else{
//         while(diff != 0){
//             head1 = head1->next;
//             diff--;
//         }
//     }
//     Node* temp1 = head1;
//     Node* temp2 = head2;
//     while(temp1){
//         if(temp1 == temp2) return temp1;
//         temp1 = temp1->next;
//         temp2 = temp2->next;
//     }
//     return NULL;
// }

// 2.Optimal. T.C -> O(2*max(l1,l2)), S.C -> O(1).
Node* checkIntersection(Node* head1, Node* head2){
    if(head1 == NULL || head2 == NULL) return NULL;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1 == temp2) return temp1;
        if(temp1 == NULL) temp1 = head2;
        if(temp2 == NULL) temp2 = head1;
    }
    return temp1;
}

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
    Node* head1 = nullptr;
    head1 = new Node(5);
    Node* head2 = head1;
    head1->next = head;
    head = fifth;
    printLL(head);
    printLL(head2);
    Node* res =  checkIntersection(head,head2) ;
    cout << res->data << endl;
    return 0;
}