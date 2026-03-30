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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode *, int>> q;
        vector<int> res;
        q.push({root, 0});

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            if(!front.first) continue;
            if(res.size()<=front.second){
                res.push_back(front.first->val);
            }

            q.push({front.first->right, front.second+1});
            q.push({front.first->left, front.second+1});
        }

        return res;
    }
};
