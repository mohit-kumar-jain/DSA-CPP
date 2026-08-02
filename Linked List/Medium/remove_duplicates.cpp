#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; 

void printLL(ListNode* head){
    if(head == NULL) cout << " ";
    ListNode* temp = head;
    while(temp){
        cout << temp->val<< " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *res = head;

    while (head && head->next)
    {
        if (head->val == head->next->val)
        {
            head->next = head->next->next;
        }
        else
        {
            head = head->next;
        }
    }

    return res;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);
    printLL(head);
    ListNode* res = deleteDuplicates(head);
    printLL(res);
    return 0;
}