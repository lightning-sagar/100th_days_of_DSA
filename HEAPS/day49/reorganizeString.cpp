class Node {
public:
    char data;
    int count;
    Node(char data, int count) {
        this->data = data;
        this->count = count;
    }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->count < b->count;
    }
};

class Solution {
public:
    std::string reorganizeString(std::string s) {
        int freq[26] = {0};
        for (char c : s) {
            freq[c - 'a']++;
        }

        std::priority_queue<Node*, std::vector<Node*>, Compare> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(new Node('a' + i, freq[i]));
            }
        }

        std::string ans;

        while (pq.size() > 1) {
            Node* a = pq.top();
            pq.pop();
            Node* b = pq.top();
            pq.pop();
            ans += a->data;
            ans += b->data;
            if (a->count > 1) {
                pq.push(new Node(a->data, a->count - 1));
            }
            if (b->count > 1) {
                pq.push(new Node(b->data, b->count - 1));
            }
        }

        if (!pq.empty()) {
            if (pq.top()->count > 1) {
                return "";
            }
            ans += pq.top()->data;
        }

        return ans;
    }
};