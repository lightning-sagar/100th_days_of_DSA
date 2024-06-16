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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(ListNode* &head,int n){
        if(n<=0 || head == NULL) return NULL;
        TreeNode* leftsubtree=helper(head,n/2);//head se mid -1 tak
         TreeNode* root=new TreeNode(head->val);
        root->left = leftsubtree;
        head=head->next;
        root->right=helper(head,n-n/2-1);//mid se end tak
        return root;

    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp=head;
        int n=0;
         while(temp){
             n++;
             temp=temp->next;
         }

         return helper(head,n);
    }
};