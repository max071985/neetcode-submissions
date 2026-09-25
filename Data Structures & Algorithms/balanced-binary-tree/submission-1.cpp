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
    int check(TreeNode* node) {
        if (!node) return 0;
        int left = check(node->left);
        int right = check(node->right);
        if (left == -1 || right == -1) {
            return -1;
        }
        if (abs(left - right) > 1) {
            return -1;
        }
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        int output = check(root);
        cout << output;
        return (output != -1);
    }
};
