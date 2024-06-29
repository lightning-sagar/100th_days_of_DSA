class graph{
    public:
    unordered_map<int, list<int>> adj;
    void addedges(int u,int v,bool dir){
        adj[u].push_back(v);
        if(!dir){
            adj[v].push_back(u);
        }
    }
    void print(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
};