// class Solution {
// public:
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         ListNode dummy(0);
//         dummy.next = head;
//         ListNode* prev = &dummy;//0-1-4-3-2-5
        
//         // moce till it come to left and store it in prev;
//         for (int i = 1; i < left; ++i) {
//             prev = prev->next;
//         }
        
//         // Reverse it until it tends to right
//         ListNode* curr = prev->next;
//         for (int i = left; i < right; ++i) {
//             ListNode* next = curr->next;
//             curr->next = next->next;
//             next->next = prev->next;
//             prev->next = next;
//         }
        
//         return dummy->next;
//     }
// };




class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;//0-1-4-3-2-5
        
        // moce till it come to left and store it in prev;
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }
            prev = prev->next;//2
        
        // Reverse it until it tends to right
        ListNode* curr = prev->next;
        for (int i = left; i < right; ++i) {
            ListNode* forward = curr->next;
            forward->next = curr;
            curr ->next = prev;
            
            // curr->next = next->next;
            // next->next = prev->next;
            // prev->next = next;
        }
        
        return dummy->next;
    }
};
