class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> forward(nums.size()+2);
        vector<int> backward(nums.size()+2);
        vector<int> res;
        int n = nums.size();
        forward[0] = 1;
        forward[n+1] = 1;
        backward[0] = 1;
        backward[n+1] = 1;
        for(int i=1;i<(n+1);++i){
            forward[i] = nums[i-1] * forward[i-1];
        }
        for(int i=n;i>0;--i){
            backward[i] = nums[i-1] * backward[i+1];
        }

        for(int i=1;i<(n+1);++i){
            res.push_back (backward[i+1] * forward[i-1]);
        }

        return res;
    }
};
