class Solution {
  public:
    int extractMax() {
        int max = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
        return max;
    }
};
