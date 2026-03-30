class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        vector<int> tmp;
        
        backtrack(nums, ans, tmp, 0);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& ans, 
                   vector<int>& tmp, int start) {
        
        ans.push_back(tmp);  // every state is a subset
        
        for (int i = start; i < nums.size(); i++) {

            if (i > start && nums[i] == nums[i-1]) continue;

            tmp.push_back(nums[i]);

            backtrack(nums, ans, tmp, i + 1);

            tmp.pop_back(); // backtrack
        }
    }
};