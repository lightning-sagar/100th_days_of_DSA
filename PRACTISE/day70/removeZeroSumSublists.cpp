class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode*> prefixSumMap;
        prefixSumMap[0] = dummy;
        
        int prefixSum = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            prefixSum += curr->val;
            if (prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
                ListNode* start = prefixSumMap[prefixSum]->next;
                int sum = prefixSum;
                while (start != curr) {
                    sum += start->val;
                    prefixSumMap.erase(sum);
                    start = start->next;
                }
                prefixSumMap[prefixSum]->next = curr->next;
            } else {
                prefixSumMap[prefixSum] = curr;
            }
            curr = curr->next;
        }
        
        return dummy->next;
    }
};