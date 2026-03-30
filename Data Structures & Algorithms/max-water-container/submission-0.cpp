class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        int i,j,l = heights.size();
        i = 0;
        j = l-1;
        while(i<j){
            res = max(res, min(heights[i],heights[j])*(j-i));
            if(heights[i]<=heights[j]) ++i;
            else --j;
        }

        return res;
    }
};
