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
private:
    int maxDepth(TreeNode * root){
        if(!root) return 0;
        int l_depth = maxDepth(root->left);
        int r_depth = maxDepth(root->right);
        diameter = max(diameter, l_depth+r_depth);
        return max(l_depth,r_depth) + 1;
    }
    int diameter;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;

        maxDepth(root);
        return diameter;
    }
};
