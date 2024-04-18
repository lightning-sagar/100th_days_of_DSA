class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp=head;
        vector<int> v;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int ans=0;
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]==0)
            continue;
            else
            ans+=pow(2,v.size()-i-1);
        }
        return ans;
    }
};