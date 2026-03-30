class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){

            getCombinations(nums, ans, {}, i, target);
        }

        return ans;
    }
    void getCombinations(vector<int> & nums, vector<vector<int>> & ans,  vector<int> tmp, int cur, int rem) {
        if(cur>=nums.size()) {
            if(rem==0){
                ans.push_back(tmp);
            }
            return;
        }

        if(nums[cur]>rem){
            return;
        }
        
        tmp.push_back(nums[cur]);
        rem-=nums[cur];

        if(rem==0) {
            ans.push_back(tmp);
            return;
        }

        for(int i=cur;i<nums.size();i++) {
            getCombinations(nums, ans, tmp, i, rem);
        }
    }
};
