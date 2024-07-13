class Solution {
  public:
    void linkdelete(struct Node **head, int n, int m) {

        struct Node *temp = *head;
        while(temp != NULL){
            //skip m 
            for(int i = 1; i < m && temp != NULL; i++){
                temp = temp->next;
            }
            //delete
            struct Node *del = temp->next;

            //skip n
            for(int i = 1; i <= n && del != NULL; i++){
                del = del->next;
            }
            
            temp->next = del;
            temp = temp->next;
        }
    }
};
