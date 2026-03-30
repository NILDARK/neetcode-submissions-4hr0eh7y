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
        bool isBal = true;

        maxDepth(root, isBal);

        return isBal;
    }

    int maxDepth (TreeNode * root, bool & isBalanced){
        if(!root) return 0;

        int left = maxDepth(root->left, isBalanced);
        int right = maxDepth(root->right, isBalanced);

        if(abs(left-right)>1) isBalanced = false;
        return max(left, right) + 1;
    }
};
