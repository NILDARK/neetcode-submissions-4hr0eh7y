class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0;
        int i,j, n = prices.size();
        if(n<=1) return 0;
        i = 0;
        j = i+1;
        while(j<n){
            if(prices[i]<=prices[j]){
                mx = max(mx, prices[j]-prices[i]);
                ++j;
                continue;
            }
            ++i;
            j = i+1;
        }
        return mx;
    }
};
