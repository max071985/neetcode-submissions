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
    void iterate(TreeNode* node, vector<int>* vals) {
        if (!node) return;
        if (node->left) {
            iterate(node->left, vals);
        }
        vals->push_back(node->val);
        if (node->right) {
            iterate(node->right, vals);
        }
    }
    bool isValidBST(TreeNode* root) {
        // a valid bst will generate a sorted array in a specific search:
        vector<int> sorted;
        iterate(root, &sorted);
        for (int i = 0; i < sorted.size() - 1; i++) {
            if (sorted[i] >= sorted[i + 1]) return false;
        }
        return true;
    }
};
