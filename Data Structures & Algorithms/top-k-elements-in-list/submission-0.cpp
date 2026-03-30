class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<vector<int>> cnt (nums.size()+1);
        vector<int> res;

        for(int num: nums){
            freq[num]++;
        }

        for(auto [k,v] : freq){
            cnt[v].push_back(k);
        }

        for(int i=nums.size();i>=0;--i){
            if(k<=0) break;
            for(auto itm: cnt[i]){
                res.push_back(itm);
                --k;
            }
            // if(!cnt[i].empty()) --k;
        }

        return res;

    }
};