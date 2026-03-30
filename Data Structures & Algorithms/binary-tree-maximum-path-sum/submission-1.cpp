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
constexpr int MIN = -1001;
class Solution {
public:
    int maxSum;
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        calcMaxPathForEachNode(root);
        return maxSum;
    }

    int calcMaxPathForEachNode(TreeNode * root) {
        if(!root) return MIN;

        int left = max(0,calcMaxPathForEachNode(root->left));
        int right = max(0,calcMaxPathForEachNode (root->right));
        maxSum = max(maxSum, root->val + left + right);
        return max(root->val+left, root->val+right);
    }
};
