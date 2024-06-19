#include <queue>  

class Solution {
public:
    // arr : given array
    // l : starting index of the array i.e 0 (unused in this implementation)
    // r : ending index of the array i.e size-1 (unused in this implementation)
    // k : find kth smallest element and return using this function

    int kthSmallest(int arr[], int l, int r, int k) {
        std::priority_queue<int> pq; 

        for (int i = 0; i < k; ++i) {
            pq.push(arr[i]);    
        }

        for (int i = k; i <= r; ++i) {
            if (arr[i] < pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        return pq.top();  
    }
};