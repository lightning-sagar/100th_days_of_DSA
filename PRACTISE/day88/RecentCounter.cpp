class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {
        
    }
    
    int ping(int t) {
        int temp = t - 3000;
        q.push(t);
        while(q.front() < temp)
        {
            q.pop();
        }
        return q.size();
    }
};

 