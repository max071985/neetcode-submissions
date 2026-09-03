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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // idea: use a sliding window like approach
        // find the n'th element from the start, save it as the endptr
        // use head as the n'th element from this window of size n
        // go to the next element until endptr reaches the end
        // head will point to nth element
        // -------- 
        // edge case: n = size, return the 2nd element.

        ListNode *endptr = head;
        ListNode *nthptr = head;

        // Point the endptr to the nth element
        for (int i = 0; i < n - 1; i++) {
            endptr = endptr->next;
        }
        // EDGE CASE: if n = size, then endptr->next is null
        if (!endptr->next) {
            return head->next;
        }
        // idea: leave a window of size n + 1, (make head point to the predecessor of the element we need to remove)
        endptr = endptr->next;
        while(endptr->next) {
            endptr = endptr->next;
            nthptr = nthptr->next;
        }
        nthptr->next = nthptr->next->next; // Remove the nth element from the end
        return head;
    }
};
