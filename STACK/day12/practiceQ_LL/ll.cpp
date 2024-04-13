ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next || !head->next->next) return head;
    
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *even_start = head->next;
    
    while(odd->next && even->next){
        odd->next = even->next;  
        even->next = odd->next->next;   
        odd = odd->next;
        even = even->next;
    }
    odd->next = even_start;    
    return head; 
}

//---------------------------------------------------------------------------------

ListNode* reverseList(ListNode* head) {
    if( head == NULL ) return head;
    ListNode* prev = NULL;
    ListNode* curr = head;
    while(curr!=NULL){
        ListNode* forward = curr->next;
        curr->next = prev;
        prev =curr;
        curr = forward;
    }
    return prev;
}
