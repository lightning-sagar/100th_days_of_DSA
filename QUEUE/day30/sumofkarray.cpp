int SumOfKsubArray(int arr[], int N, int k)
{
    // To store final answer
    int sum = 0;
 
    // Find all subarray
    for (int i = 0; i < N; i++) {
        // To store length of subarray
        int length = 0;
        for (int j = i; j < N; j++) {
            // Increment the length
            length++;
 
            // When there is subarray of size k
            if (length == k) {
                // To store maximum and minimum element
                int maxi = INT_MIN;
                int mini = INT_MAX;
 
                for (int m = i; m <= j; m++) {
                    // Find maximum and minimum element
                    maxi = max(maxi, arr[m]);
                    mini = min(mini, arr[m]);
                }
 
                // Add maximum and minimum element in sum
                sum += maxi + mini;
            }
        }
    }
    return sum;
}