class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        int mod = 1e9 + 7;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int leftCount = i - left[i];
            int rightCount = right[i] - i;
            sum = (sum + (long long)arr[i] * leftCount * rightCount) % mod;
        }

        return (int)sum;
    }
};
