class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, unsigned int> mp;
        for (auto num: nums){
            mp[num]++;
            if(mp[num]>1) return true;
        }
        return false;
    }
};
