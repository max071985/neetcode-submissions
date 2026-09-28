/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
// Time: O(n) Space: O(n)
    int helper(TreeNode* node, int biggestVal) {
        if (!node) return 0;
        if (node->val >= biggestVal) {
            return helper(node->left, node->val) + helper(node->right, node->val) + 1;
        }
        return helper(node->left, biggestVal) + helper(node->right, biggestVal);
    }
    int goodNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return helper(root, root->val);
    }
};
