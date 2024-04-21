class StockSpanner {
public:
stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int p ) {
        int spam = 1;
        while(!st.empty() && st.top().first<=p){
            spam += st.top().second;
            st.pop();
        }
        st.push({p,spam});
        return spam;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */