class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int l, int r){
        int mid;
        if(l>r) return -1;

        mid = (l+r)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target){
            return binarySearch(nums, target, l, mid-1);
        } else {
            return binarySearch(nums, target, mid+1, r);
        }
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;++i){
            if(matrix[i][n-1]>=target){
                int res = binarySearch(matrix[i], target, 0, n-1);
                if(res!=-1) return true;
                return false;
            }
        }
        return false;
    }
};
