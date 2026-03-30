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
#include <cstring>

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return ""; 
        vector<int> tree_vec;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode * cur = q.front();
            q.pop();
            if(!cur){
                tree_vec.push_back(-1001);
            } else {
                tree_vec.push_back(cur->val);
                q.push(cur->left);
                q.push(cur->right);
            }
        }

        int tree_size = tree_vec.size();

        string res (tree_size * sizeof(int), '*');
        char * ptr = res.data();
        for(int val: tree_vec){
            memcpy(ptr, &val, sizeof(int));
            ptr+=sizeof(int);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;
        vector<int> tree;
        int tree_size = data.size()/sizeof(int);
        char * ptr = data.data();
        for(int i=0;i<tree_size;++i){
            tree.push_back(*(int*)ptr);
            ptr+=sizeof(int);
        }

        return createTree(tree);
    }

    TreeNode * createTree(vector<int>& tree_vec){
        if(tree_vec.empty()) return nullptr;

        queue<TreeNode *> q;
        TreeNode * root = new TreeNode(tree_vec[0]);
        q.push(root);
        int i = 1;
        while(!q.empty() && i<tree_vec.size()){
            TreeNode * cur = q.front();
            q.pop();
            if(tree_vec[i]!=-1001){
                cur->left = new TreeNode(tree_vec[i]);
                q.push(cur->left);
            }
            i++;
            if(i<tree_vec.size() && tree_vec[i]!=-1001){
                cur->right = new TreeNode (tree_vec[i]);
                q.push(cur->right);
            }
            i++;
        }

        return root;
    }
};
