/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr && l2 == nullptr) return nullptr; // Check if both lists are empty
    
    int carry = 0;
    ListNode* resultHead = nullptr;
    ListNode* resultTail = nullptr;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;
        
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10; // Calculate carry
        sum %= 10; // Calculate remainder
        
        ListNode* newNode = new ListNode(sum); // Create a new node with the calculated sum
        
        if (resultHead == nullptr) {
            resultHead = newNode;
            resultTail = newNode;
        } else {
            resultTail->next = newNode;
            resultTail = resultTail->next;
        }
    }

    return resultHead;
}

};