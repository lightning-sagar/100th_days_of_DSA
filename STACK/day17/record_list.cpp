class Solution {
private:
    ListNode* reverseLL(ListNode* head){
        
        if (!head || !head->next) return head;
        ListNode * prev = nullptr;
        ListNode * next = nullptr;
        ListNode * temp = head;

        while (temp){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        // step 1 find the start of second half of ll
        ListNode * slow = head;
        ListNode * fast = head;
        ListNode* head2 = nullptr;

        while (fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next ->next;
        }
        // step2: reverse the second half
        head2 = reverseLL(slow->next);

        // disconnect both halves
        slow->next =nullptr;
 
        // 3 finally point the ith element of each part
        ListNode * a = head;
        ListNode * b = head2;

        while (a && b){
            ListNode * a2 = a->next;
            ListNode * b2 = b->next;
            b->next = a2;
            a->next = b;
            if (a2 && !b2) {
                b->next = a2;
                return;
            }
            a=a2; b=b2;
        }   
    }
};