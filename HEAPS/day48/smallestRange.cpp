class node{
    public:
    int data;
    int row;
    int col;

    node(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};
class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

vector<int> smallestRange(vector<vector<int>>& nums) {
    int min = INT_MAX, max = INT_MIN;
    priority_queue<node*, vector<node*>, compare> pq;

    int n = nums.size();

    for(int i=0; i<n; i++){
        pq.push(new node(nums[i][0], i, 0));
        max = max > nums[i][0] ? max : nums[i][0];
    }

    vector<int> ans;

    while(!pq.empty()){
        node* top = pq.top();
        pq.pop();
        if(max - top->data < min){       
            min = max - top->data;
            ans = {top->data, max};
        }
        if(top->col + 1 < nums[top->row].size()){
            pq.push(new node(nums[top->row][top->col+1], top->row, top->col+1));
            max = max > nums[top->row][top->col+1] ? max : nums[top->row][top->col+1];
        }
    }
    return ans;
}