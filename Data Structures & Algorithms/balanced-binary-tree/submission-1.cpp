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
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        func(root, ans);
        return ans;
    }

    int func(TreeNode* root, bool &ans)
    {
        if (!root || !ans) return 0;

        int lh = func(root->left, ans);
        int rh = func(root->right, ans);

        if (abs(lh - rh) > 1) ans = false;

        return max(lh, rh) + 1;
    }
};


