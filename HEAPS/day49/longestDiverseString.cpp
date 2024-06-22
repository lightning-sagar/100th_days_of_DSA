
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

string longestDiverseString(int a, int b, int c) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    pq.push(new Node('a', a));
    pq.push(new Node('b', b));
    pq.push(new Node('c', c));
}