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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string main = "";
        string sub = "";

        inorder(root, main);
        inorder(subRoot, sub);

        return main.find(sub) != string::npos;
    }

    void inorder(TreeNode* root, string &s)
    {
        if (!root){
            s+= "$#";
            return;
        }

        s += "$";
        s += to_string(root->val);

        inorder(root->left, s);
        inorder(root->right, s);
    }
};
