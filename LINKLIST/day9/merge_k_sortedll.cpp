#include<iostream>
#include<vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode() {
        this->val = 0;
        this->next = NULL;
    }
    ListNode(int data) {
        this->val = data;
        this->next = NULL;
    }
};

ListNode* mergeTwo(ListNode* l1, ListNode* l2) {
    if (l1 == NULL && l2 == NULL) return NULL;
    ListNode* ans = new ListNode(-1);
    ListNode* mans = ans;
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            mans->next = l1;
            mans = l1;
            l1 = l1->next;
        } else {
            mans->next = l2;
            mans = l2;
            l2 = l2->next;
        }
    }
    if (l1) {
        mans->next = l1;
    }
    if (l2) {
        mans->next = l2;
    }
    return ans->next;
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=NULL;
        for(auto& list:lists){
            head=mergeTwo(head,list);
        }
        return head;
    
}