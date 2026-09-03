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
        ListNode *output = l1, *newListTail;
        int carry = 0;
        while (l1 && l2) {
            int sumVal = l1->val + l2->val + carry;
            carry = sumVal / 10; // 1 or 0
            l1->val = sumVal % 10;
            newListTail = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int sumVal = l1->val + carry;
            carry = sumVal / 10;
            l1->val = sumVal % 10;
            newListTail = l1;
            l1 = l1->next;
        }
        if (l2) {
            newListTail->next = l2;
        }
        while (l2) {
            int sumVal = l2->val + carry;
            carry = sumVal / 10;
            l2->val = sumVal % 10;
            newListTail = l2;
            l2 = l2->next;
        }
        if (carry) {
            newListTail->next = new ListNode(carry);
        }
        return output;
    }
};
