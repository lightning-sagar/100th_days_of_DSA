/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
int findlength(ListNode* head){
    int i =0;
    ListNode* temp = head;
    while(temp != NULL){
        temp = temp->next;
        i++;
    }
    return i;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) return head;
    int len = findlength(head);
        k = (k % len);
    if(k == 0) return head;
    ListNode* newptr = head; 
    ListNode* temp = head;
    for (int i = 0; i < len - k - 1; ++i) {
        temp = temp->next;
    }
    ListNode* newHead = temp->next; 
    temp->next = nullptr;
    ListNode* tail = newHead;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = newptr;

    return newHead;
}
};