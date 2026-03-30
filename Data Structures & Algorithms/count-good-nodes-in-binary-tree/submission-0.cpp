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
    int goodNodes(TreeNode* root, int mx = -101) {
        if(!root) return 0;

        bool isGood = false;
        if(root->val>=mx){
            isGood = true;
        }

        mx = max(mx, root->val);

        return goodNodes(root->left, mx) + goodNodes(root->right, mx) + (int) isGood;
    }
};
