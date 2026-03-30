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
    int cur_indx;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> indx_map;
        for(int i=0;i<inorder.size();++i){
            indx_map[inorder[i]] = i;
        }
        cur_indx = 0;
        return buildTreeHelper(0, inorder.size()-1, indx_map, preorder, inorder);
    }

    TreeNode * buildTreeHelper(int left, int right,unordered_map<int,int> & indx_map, vector<int>& preorder, vector<int>& inorder){
        if(left>right) return nullptr;

        int index = indx_map[preorder[cur_indx]];
        TreeNode * root = new TreeNode(preorder[cur_indx++]);
        root->left = buildTreeHelper(left, index-1, indx_map, preorder, inorder);
        root->right = buildTreeHelper(index+1, right, indx_map, preorder, inorder);

        return root;
    }

};
