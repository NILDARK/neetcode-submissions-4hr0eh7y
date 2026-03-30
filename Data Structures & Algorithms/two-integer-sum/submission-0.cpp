class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> mp;
        for (int i=0;i<nums.size();++i){
            mp[nums[i]].push_back(i);
        }

        for(int i=0;i<nums.size();++i){
            for (auto j: mp[target - nums[i]]){
                if(i<j){
                    return vector<int> ({i,j});
                }
            }
        }
    }
};
