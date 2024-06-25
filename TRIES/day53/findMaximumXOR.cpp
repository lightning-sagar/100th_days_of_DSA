class triNode {
public:
    triNode* children[2];
    
    triNode() {
        children[0] = NULL;
        children[1] = NULL;
    }
};

class Solution {
public:
    void insert(triNode* root, int num) {
        triNode* temp = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(temp->children[bit] == NULL) {
                temp->children[bit] = new triNode();
            }
            temp = temp->children[bit];
        }
    }
    
    int findMaximumXOR(vector<int>& nums) {
        triNode* root = new triNode();
        for(int num : nums) {
            insert(root, num);
        }
        
        int max_xor = 0;
        for(int num : nums) {
            triNode* temp = root;
            int current_xor = 0;
            for(int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if(temp->children[1 - bit] != NULL) {
                    current_xor = (current_xor << 1) | 1;
                    temp = temp->children[1 - bit];
                } else {
                    current_xor = (current_xor << 1);
                    temp = temp->children[bit];
                }
            }
            max_xor = max(max_xor, current_xor);
        }
        
        return max_xor;
    }
};