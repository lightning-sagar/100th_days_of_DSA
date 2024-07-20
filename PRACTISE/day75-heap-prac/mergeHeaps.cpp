class Solution{
    public:
    void adjust(vector<int> &heap,int i)
    {
        int N = heap.size();
        int item = heap[i];
        int j = 2*i+1;
        
        while(j < N)
        {
            if(j < N-1 && heap[j] < heap[j+1]) j++;
            if(item > heap[j]) break;
            
            heap[i] = heap[j];
            i = j;
            j = 2*i + 1;
        }
        
        heap[i] = item;
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) 
    {
        a.insert(a.end(),b.begin(),b.end());
        
        for(int i = a.size()/2; i >= 0; i--)
        {
            adjust(a,i);
        }
        
        return a;
    }
};