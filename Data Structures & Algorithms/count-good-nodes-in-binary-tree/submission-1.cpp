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
    int goodNodes(TreeNode* root) {

        int ans = 0;
        if (root) func(root, root->val, ans);

        return ans;
    }

    void func(TreeNode* root, int maxVal, int &ans)
    {
        if (!root) return;
        if (root->val >= maxVal) {
            ans++;
            maxVal = root->val;
        }
        
        func(root->left, maxVal, ans);
        func(root->right, maxVal, ans);
    }
};
