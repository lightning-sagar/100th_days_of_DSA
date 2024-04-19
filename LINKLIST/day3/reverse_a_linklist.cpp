ListNode* prev = head; // Point to the node before the sublist to be reversed
        
        // Move to the node before the sublist to be reversed
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }
        
        ListNode* sub_list = prev->next; // Pointer to the start of the sublist to be reversed
        
        // Move to the end of the sublist to be reversed
        for (int i = left; i < right; ++i) {
            sub_list = sub_list->next;
        }
        
        ListNode* t1 = prev; // Store the node before the sublist for reconnection later
        ListNode* t2 = sub_list->next; // Store the node after the sublist for reconnection later
        
        // Reverse the sublist between left and right indices
        reverse(sub_list);
        
        // Reconnect the sublist back into the original list
        prev->next = sub_list;
        t1->next = t2;
        
        return head;