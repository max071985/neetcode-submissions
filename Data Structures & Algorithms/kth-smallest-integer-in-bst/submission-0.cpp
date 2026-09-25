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
    utilizing the BST trait of O(n) sorted array, we can get the k'th smallest element in O(n) time.
    and O(n) extra space (O(n) stack + O(n) array)
*/
    void retSort(TreeNode *root, vector<int>* arr) {
        if (!root) return;
        retSort(root->left, arr);
        arr->push_back(root->val);
        retSort(root->right, arr);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> sorted;
        retSort(root, &sorted);
        return sorted[k - 1];
    }
};
