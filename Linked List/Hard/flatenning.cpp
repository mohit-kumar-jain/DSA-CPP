#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
        child = nullptr;
    }
    Node(int data, Node *next, Node *child)
    {
        this->data = data;
        this->next = next;
        this->child = child;
    }
};

// Brute. T.C -> O(N x M) + O(N x M log(N x M)) + O(N x M) , S.C ->O(N*M)+O(N*M).
// Node* convertArrToLinkedList(vector<int>& nums){
//     if(nums.size() == 0) return NULL;
//     Node* dummyNode = new Node(-1);
//     Node* temp = dummyNode;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         temp->child = new Node(nums[i]);
//         temp = temp -> child;
//     }
//     return dummyNode->child;
// }
// Node* flattenLL(Node* head){
//     Node* temp = head;
//     vector<int> res;
//     while(temp){
//         Node* t2 = temp;
//         while(t2){
//             res.push_back(t2->data);
//             t2 = t2->child;
//         }
//         temp = temp->next;
//     }
//     sort(res.begin(),res.end());
//     return convertArrToLinkedList(res);
// }

// Optimal. T.C -> O(2N*M), S.C -> O(1).

Node* merge2Lists(Node* l1, Node* l2){
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    while(l1 && l2){
        if(l1->data < l2->data){
            res->child = l1;
            res = l1;
            l1 = l1->child;
        }
        else{
            res->child = l2;
            res = l2;
            l2 = l2->child;
        }
        res->next = NULL;
    }
    if(l1)
        res->child = l1;
    else
        res->child = l2;
    Node* ans = dummyNode->child;
    delete dummyNode;
    return ans;
}

Node* flattenLL(Node* head){
    if(head == NULL || head->next == NULL)
        return head;
    head->next = flattenLL(head->next);
    return merge2Lists(head, head->next);
}

void printOrgLL(Node* head, int depth){
    while(head){
        cout << head->data;
        if(head->child){
            cout << " -> ";
            printOrgLL(head->child, depth + 1);
        }
        if(head->next){
            cout << endl;
            for(int i = 0; i < depth; i++)
                cout << "| ";
        }
        head = head->next;
    }
    cout << endl;
}

void printLL(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

int main()
{
    Node* head = new Node(5);
    head->child = new Node(7);
    head->child->child = new Node(8);
    head->child->child->child = new Node(30);

    head->next = new Node(10);
    head->next->child = new Node(20);

    head->next->next = new Node(19);
    head->next->next->child = new Node(22);
    head->next->next->child->child = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->child = new Node(35);
    head->next->next->next->child->child = new Node(40);
    head->next->next->next->child->child->child = new Node(45);
    printOrgLL(head,0);
    cout << endl;
    head = flattenLL(head);
    printLL(head);
    return 0;
}