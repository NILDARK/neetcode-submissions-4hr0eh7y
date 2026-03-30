class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = *max_element(piles.begin(), piles.end());
        int l=1, r= mx, mid, k;
        long long tt;
        while(l<=r){
            mid = (l+r)/2;
            tt = 0;
            for(int p: piles){
                tt += ceil(static_cast<double>(p)/mid);
            }
            if(tt<=h){
                k = mid;
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }

        return k;
    }
};