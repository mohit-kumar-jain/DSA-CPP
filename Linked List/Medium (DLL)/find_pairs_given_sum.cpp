#include<bits/stdc++.h>               
using namespace std;
              
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data = data;
        prev = NULL;
        next = NULL;
    }
    Node(int data,Node* prev ,Node* next = nullptr){
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

void printDLL(Node* head){
    if(head == NULL) cout << " ";
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Brute. T.C -> O(N*N), S.C -> O(n).
// vector<vector<int>> findPairs(Node* head,int sum){
//     if(head == NULL || head->next == NULL) return {{}};
//     vector<vector<int>> res;
//     Node* temp = head;
//     while(temp){
//         Node* nextNode = temp->next;
//         while(nextNode && temp->data + nextNode->data <= sum){
//             if(temp->data + nextNode->data == sum){
//                 res.push_back({temp->data,nextNode->data});
//             }
//             nextNode = nextNode->next; 
//         }
//         temp = temp->next;
//     }
//     return res;
// }

// Optimal. T.C -> O(N), S.C -> O(1).
Node* findLast(Node* head){
    Node* temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    return temp;
}
vector<vector<int>> findPairs(Node* head,int sum){
    if(head == NULL || head->next == NULL) return {{}};
    vector<vector<int>> res;
    Node* first = head;
    Node* last = findLast(head);
    while(first->data < last->data){
        if(first->data + last->data == sum){
            res.push_back({first->data,last->data});
            first = first->next;
            last = last->prev;
        }else if(first->data + last->data < sum){
            first = first->next;
        }else{
            last = last->prev;
        }
    }
    return res;
}

int main() {
    Node* head = new Node(1);
    Node* first = new Node(2,head);
    Node* second = new Node(3,first);
    Node* third = new Node(4,second);
    Node* fourth = new Node(5,third);
    Node* fifth = new Node(6,fourth);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    printDLL(head);
    vector<vector<int>> res = findPairs(head,7);
    for(auto row : res){
        for(auto val : row){
            cout << val <<" " ;
        }
        cout << endl;
    }
    return 0;
}