class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int mx = -10001;
        map<int, int> win_freq;
        int n = nums.size();
        for(int i=0;i<k;++i){
            mx = max(mx, nums[i]);
            win_freq[nums[i]]++;
        }

        res.push_back(mx);

        for(int l=1;l+k<=n;++l){
            int r = l+k-1;
            win_freq[nums[l-1]]--;
            win_freq[nums[r]]++;
            if(win_freq[nums[l-1]] == 0) win_freq.erase(nums[l-1]);
            mx = win_freq.rbegin()->first;
            res.push_back(mx);
        }

        return res;
    }
};