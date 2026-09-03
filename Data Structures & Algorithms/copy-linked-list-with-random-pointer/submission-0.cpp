/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // idea: create a hashmap [node, newnode] and adjust newnode pointers as needed.
        // Time: O(n) - 2 passes - one for adding all nodes, the other to map next and random addresses.
        // Space: O(n) - hashmap of 2n size.
        unordered_map<Node*, Node*> mapping;
        Node *tmpHead = head;
        // First pass: create a copy for each node
        while (tmpHead) {
            if (!mapping.contains(tmpHead)) {
                mapping[tmpHead] = new Node(tmpHead->val);
            }
            tmpHead = tmpHead->next;
        }
        // Second pass: map next and random pointers:
        tmpHead = head;
        while (tmpHead) {
            Node* copyNode = mapping[tmpHead];
            Node* copyNext = mapping[tmpHead->next];
            Node* copyRnd = mapping[tmpHead->random];
            copyNode->next = copyNext;
            copyNode->random = copyRnd;
            tmpHead = tmpHead->next;
        }
        // Return the start of the deep-copied list.
        return mapping[head];
    }
};
