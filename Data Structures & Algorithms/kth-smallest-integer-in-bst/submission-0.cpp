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
    int kth;
    int num;
public:
    int kthSmallest(TreeNode* root, int k) {
        kth = k;

        inorderTraversal(root);
        return num;
    }

    void inorderTraversal(TreeNode * root){
        if(!root) return;

        inorderTraversal(root->left);
        kth-=1;
        if(kth==0) num = root->val;
        inorderTraversal(root->right);
    }
};
