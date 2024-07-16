class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        
        int n = deck.size();
        deque<int> dq;
        
        for (int i = 0; i < n; ++i) {
            dq.push_back(i);
        }
        
        vector<int> result(n, 0);
        
        for (int i = 0; i < n; ++i) {
            result[dq.front()] = deck[i];
            dq.pop_front();
            
            if (!dq.empty()) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        
        return result;
    }
};