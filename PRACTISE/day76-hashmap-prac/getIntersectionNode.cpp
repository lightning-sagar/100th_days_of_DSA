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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = findlength(headA);
        int l2 = findlength(headB);
        int diff = l1-l2;
        if(diff>0){//mean l1 is greater
            while(diff--){
                headA= headA ->next;
            }
        }
        else{
            while(diff++){
                headB= headB ->next;
            }
        }
        while(headA != headB && headA!=NULL){
            headA = headA ->next;
            headB = headB->next;
        }
        return headA;
    }
};