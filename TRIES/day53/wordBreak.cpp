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

