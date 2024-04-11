class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        tail->next = l1 ? l1 : l2;
        
        return dummy.next;
    }
    
    int length(ListNode* head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }
    
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        int len = length(head);
        
        ListNode dummy(0);
        dummy.next = head;
        
        for (int sz = 1; sz < len; sz <<= 1) {
            ListNode* prev = &dummy;
            ListNode* curr = dummy.next;
            
            while (curr) {
                ListNode* left = curr;
                ListNode* right = split(left, sz);
                curr = split(right, sz);
                
                prev->next = merge(left, right);
                while (prev->next) prev = prev->next;
            }
        }
        
        return dummy.next;
    }
    
    ListNode* split(ListNode* head, int sz) {
        if (!head) return nullptr;
        
        for (int i = 1; head->next && i < sz; ++i) {
            head = head->next;
        }
        
        ListNode* rest = head->next;
        head->next = nullptr;
        
        return rest;
    }
};
