class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n), right(n);
        int mx = 0;
        if(n<=1) return 0;
        left[0] = 0;
        for(int i =1;i<n;++i){
            left[i] = max(height[i-1], left[i-1]);
        }
        right[n-1] = 0;
        for(int i=n-2;i>=0;--i){
            right[i] = max(height[i+1], right[i+1]);
        }
        // for(int i=0;i<n;i++){
        //     cout<<left[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<right[i]<<" ";
        // }
        // cout<<endl;
        int mx_arr = 0;
        for(int i=0;i<n;++i){
            int tmp = min(left[i], right[i]) - height[i];
            if(tmp>0) mx_arr+=tmp;
        }
        return mx_arr;
    }
};
