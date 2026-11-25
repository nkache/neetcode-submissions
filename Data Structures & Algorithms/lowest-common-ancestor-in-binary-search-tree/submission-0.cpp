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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < q->val) return func(root, p->val, q->val);
        return func(root, q->val, p->val);
    }

    TreeNode* func(TreeNode* root, int p, int q) {
        if (!root) return root;

        if (root->val > q) return func(root->left, p, q);
        if (root->val < p) return func(root->right, p, q);

        return root;
    }
};
