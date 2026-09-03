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
    bool hasCycle(ListNode* head) {
        // idea: we can alter the list, so just put a dummy value : 1001 on every passed node.
        while (head) {
            if (head->val == 1001) return true;
            head->val = 1001;
            head = head->next;
        }
        return false;
    }
};
