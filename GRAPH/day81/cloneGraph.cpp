/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*,Node*> mp;
        queue<Node> q;
        q.push(node);
        mp[node] = new Node(node->val);
        while (!q.empty())
        {
            Node* fNOde = q.front();
            q.pop();
            for(auto neigh:fNOde->neighbors){
                if(mp.find(neigh) == mp.end()){
                    mp[neigh] = new Node(neigh->val);
                    q.push(neigh);
                }
                mp[fNOde]->neighbors.push_back(mp[neigh]);
            }
        }
        return mp[node];
        
    }
};