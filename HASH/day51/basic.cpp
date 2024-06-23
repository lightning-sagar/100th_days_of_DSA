#include<iostream>
#include<unordered_map>

using namespace std;
bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,bool>  l;
        ListNode* temp = head;
        while(temp!=NULL){
            if(l.find(temp)==l.end()){
                l[temp] = true;

            }
            else{
                return true;

            }
            temp = temp->next;
        }
        return false;

    }
int main(){
    //freq of a string
    int str = "geeksforgeeks";
    unordered_map<char,int>freq;
    for (char ch : str){
        freq[ch]++;
    }
    for (auto x : freq){
        cout<<x.first<<" "<<x.second<<endl;
    }
    
}