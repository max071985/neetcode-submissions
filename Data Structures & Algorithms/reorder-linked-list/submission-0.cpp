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
    void reorderList(ListNode* head) {
        ListNode *fast, *slow;
        slow = head;
        fast = head;
        // find the middle using fast/slow pointers
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse the last half
        ListNode *prev = nullptr;
        ListNode *curr = slow;
        while (curr != nullptr) {
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        // prev is the head of the 2nd half
        // zigzag
        ListNode *head1 = head;
        ListNode *head2 = prev;
        while (head2->next != nullptr) {
            ListNode *tmp = head1->next;
            head1->next = head2;
            head2 = head2->next;
            head1->next->next = tmp;
            head1 = tmp;
        }
    }
};
