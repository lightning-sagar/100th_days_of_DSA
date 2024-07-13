class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalPoints;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        int index = 0;

        while (curr && curr->next) {
            if (prev && ((curr->val > prev->val && curr->val > curr->next->val) || 
                         (curr->val < prev->val && curr->val < curr->next->val))) {
                criticalPoints.push_back(index);
            }
            prev = curr;
            curr = curr->next;
            index++;
        }

        if (criticalPoints.size() < 2) {
            return {-1, -1};
        }

        int minDist = INT_MAX;
        for (int i = 1; i < criticalPoints.size(); i++) {
            minDist = min(minDist, criticalPoints[i] - criticalPoints[i - 1]);
        }

        int maxDist = criticalPoints.back() - criticalPoints.front();

        return {minDist, maxDist};
    }
};
