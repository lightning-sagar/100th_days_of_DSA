/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        while(temp!=NULL && temp->next!=NULL){
            temp = temp->next->next;
            head = head->next;
            if(temp==head)
                return true;
        }
        return false;
    }
};