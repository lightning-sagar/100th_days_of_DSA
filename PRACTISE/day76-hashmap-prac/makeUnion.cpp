    class Solution
    {
        public:
        struct Node* makeUnion(struct Node* head1, struct Node* head2)
        {
            // code here
            unordered_map<int,int> mp;
            Node* temp = head1;
            while(temp!=NULL)
            {
                mp[temp->data]++;
                temp=temp->next;
            }
            temp = head2;
            while(temp!=NULL)
            {
                mp[temp->data]++;
                temp=temp->next;
            }
            temp = head1;
            while(temp!=NULL)
            {
                temp->data = mp[temp->data];
                temp=temp->next;
            }
            return head1;
        }
    };