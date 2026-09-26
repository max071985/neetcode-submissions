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
    vector<int> rightSideView(TreeNode* root) {
        // Idea: in a BFS, those values are the last values of each row - O(n) time and O(n) space
        queue<pair<TreeNode*, int>> q;
        vector<int> output;
        if (!root) return output;
        q.push({root, 0});
        while (!q.empty()) {
            pair<TreeNode*, int> currVal = q.front();
            q.pop();
            // If this is the last value of a row, push it to output
            if (!q.empty()) {
                if (currVal.second != q.front().second) {
                    output.push_back(currVal.first->val);
                }
            }
            // Edge case for empty stack first / last element
            else {
                output.push_back(currVal.first->val);
            }
            if (currVal.first->left)
                q.push({currVal.first->left, currVal.second + 1});
            if (currVal.first->right)
                q.push({currVal.first->right, currVal.second + 1});
        }
        return output;
    }
};
