class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
    int n = q.size();
    vector<int> storek; // Storing first k elements

    // Push the first k elements into the vector
    for (int i = 0; i < k && !q.empty(); i++) {
        storek.push_back(q.front());
        q.pop();
    }

    // Reverse the first k elements
    reverse(storek.begin(), storek.end());

    // Push the remaining elements back to the queue
   while (!q.empty()) {
        storek.push_back(q.front());
        q.pop();
    } 

    // Push all elements from the vector back to the queue
    for (int num : storek) {
        q.push(num);
    }

    return q;
   
  }

};