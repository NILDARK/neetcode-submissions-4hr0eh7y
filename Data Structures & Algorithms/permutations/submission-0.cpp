class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        vector<bool> visited(nums.size(), false);

        getPermutations(nums, ans, tmp, visited, 0);
        return ans;
    }

    void getPermutations(vector<int>& nums, vector<vector<int>>& ans, vector<int> & tmp, vector<bool>& visited, int cur){
        if(tmp.size()==nums.size()){
            ans.push_back(tmp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(visited[i]) continue;
            visited[i] = true;
            tmp.push_back(nums[i]);
            getPermutations(nums, ans, tmp,visited, i);
            tmp.pop_back();
            visited[i] = false;
        }
    }
};
