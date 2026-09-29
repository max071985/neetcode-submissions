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
/*
    Time: O(n) (dfs)
    Space: O(n) callstack
*/
    int helper(TreeNode* node, int* maxVal) {
        if (!node) return -1000;

        // Maxes: 
        // left only
        // right only
        // current node only
        // left + current
        // right + current
        // left + right + current
        int leftMax = helper(node->left, maxVal);
        int rightMax = helper(node->right, maxVal);
        int currMax = node->val;
        int leftCurr = leftMax + currMax;
        int rightCurr = rightMax + currMax;
        int leftRightCurr = leftMax + rightMax + currMax;
        int localMax = max(leftMax, rightMax);

        // Find the local Max
        localMax = max(localMax, currMax);
        localMax = max(localMax, leftCurr);
        localMax = max(localMax, rightCurr);
        localMax = max(localMax, leftRightCurr);

        // if the new Max is biggest found so far, update it
        if (localMax > *maxVal) {
            *maxVal = localMax;
        }

        // if the current max is including the current node, the caller can get this max value
        if (localMax == currMax 
        || localMax == leftCurr 
        || localMax == rightCurr 
        /*|| localMax == leftRightCurr*/)
            return localMax;
        
        // else return the best option that includes it and keeps a simple path (lc or rc or c)
        int newVal = max(currMax, leftCurr);
        newVal = max(newVal, rightCurr);
        //newVal = max(leftRightCurr, newVal);
        return newVal;
    }
    int maxPathSum(TreeNode* root) {
        int output = -1000;
        helper(root, &output);
        return output;
    }
};
