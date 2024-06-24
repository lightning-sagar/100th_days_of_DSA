#include<iostream>
using namespace std;
class triNode{
    public:
    char data;
    triNode* children[26];
    bool isTerminal;

    triNode(char data){
        this->data = data;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

void insert(triNode* root, string word){
    triNode* temp = root;
    for(int i=0;i<word.length();i++){
        int index = word[i] - 'a';
        // creating new node
        if(temp->children[index] == NULL){
            temp->children[index] = new triNode(word[i]);
        }
        // moving to next node
        temp = temp->children[index];
    }
    //end of word
    temp->isTerminal = true;
}
