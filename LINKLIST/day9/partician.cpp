//the difficult code i have ever done

ListNode* partition(ListNode* head, int x) {
        ListNode* smaller_dummy = new ListNode(0);
        ListNode* smaller_tail = smaller_dummy;

        ListNode* larger_dummy = new ListNode(0);
        ListNode* larger_tail = larger_dummy;

        ListNode* temp = head;

        while(temp) {
            if(temp->val < x) {
                smaller_tail->next = temp;
                smaller_tail = smaller_tail->next;
            } else {
                larger_tail->next = temp;
                larger_tail =larger_tail->next;
            }
            temp = temp->next;
        }

        larger_tail->next = nullptr;
        smaller_tail->next = larger_dummy->next;

        return smaller_dummy->next;
    }