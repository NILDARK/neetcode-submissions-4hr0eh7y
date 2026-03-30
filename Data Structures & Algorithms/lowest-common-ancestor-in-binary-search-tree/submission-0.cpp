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
        if(!root || p==root || q==root) return root;

        TreeNode* lca_left = lowestCommonAncestor (root->left, p, q);
        TreeNode* lca_right = lowestCommonAncestor(root->right, p, q);

        if(lca_left && lca_right) return root;
        else if(lca_left) return lca_left;
        else return lca_right;
    }
};
