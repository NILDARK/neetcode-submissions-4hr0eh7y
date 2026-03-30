class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        int n = nums.size();
        for(int i =0;i<n;i++){
            getSubsets(nums, ans, {}, i);
        }

        return ans;
    }

    void getSubsets(vector<int>& nums, vector<vector<int>> & ans, vector<int> tmp, int i){
        if(i>=nums.size()){
            ans.push_back(tmp);
            return;
        }

        tmp.push_back(nums[i]);
        ans.push_back(tmp);
        for(int k=i+1;k<nums.size();k++){
            getSubsets(nums, ans, tmp, k);
        }
    }
};