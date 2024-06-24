class triNode {
public:
    char data;
    triNode* children[26];
    bool isTerminal;
    int childcount;
    
    triNode(char data) {
        this->data = data;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childcount = 0;
    }
};

class Solution {
public:
    void insert(triNode* root, string word) {
        triNode* temp = root;
        for(int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            // creating new node
            if(temp->children[index] == NULL) {
                temp->children[index] = new triNode(word[i]);
                temp->childcount++;
            }
            // moving to next node
            temp = temp->children[index];
        }
        // end of word
        temp->isTerminal = true;
    }
    
    void lca(triNode* root, string word, string& ans) {
        for(int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if(root->childcount == 1 && !root->isTerminal) {
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];  // Move to the next Trie node
            } else {
                break;
            }
        }
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // using trie
        triNode* root = new triNode('\0');
        for(int i = 0; i < strs.size(); i++) {
            insert(root, strs[i]);
        }
        string first = strs[0];
        string ans = "";
        lca(root, first, ans);
        return ans;
    }
};