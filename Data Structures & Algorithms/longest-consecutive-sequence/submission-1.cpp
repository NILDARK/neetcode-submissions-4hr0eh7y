class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        unordered_map<int,int> trace;
        int res = 0;
        for (auto num: nums){
            mp[num]++;
        }
        vector<int> new_nums;
        for(auto [k,v]: mp){
            new_nums.push_back(k);
        }

        for(auto num: new_nums){
            if(mp.count(num)==0) {
                continue;
            }
            trace[num] = 1;
            int i = num, cnt=0;
            while(mp.count(i-1)){
                ++cnt;
                mp.erase(i-1);
                --i; 
            }
            trace[num]+=cnt;
            i = num;
            while(mp.count(i+1)){
                trace[i+1] = trace[i]+1;
                mp.erase(i+1);
                ++i;
            }
            mp.erase(num);
        }
        for(auto [k,v]: trace){
            res = max(res,v);
        }
        return res;
    }
};
