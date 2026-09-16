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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> output;
        if (!root) return output;
        q.push({root, 0});
        int lastLevel = -1;
        
        while (!q.empty()) {
            vector<int> iLvl;
            auto frontVal = q.front();
            q.pop();
            TreeNode* currNode = frontVal.first;
            int currLevel = frontVal.second;
            if (currNode->left) q.push({currNode->left, currLevel + 1});
            if (currNode->right) q.push({currNode->right, currLevel + 1});

            iLvl.push_back(currNode->val);

            while(q.front().second == currLevel) {
                auto nextVal = q.front();
                TreeNode *nextNode = nextVal.first;
                iLvl.push_back(nextNode->val);
                if (nextNode->left) q.push({nextNode->left, currLevel + 1});
                if (nextNode->right) q.push({nextNode->right, currLevel + 1});
                q.pop();
            }
            output.push_back(iLvl);
        }
        return output;
    }
};
