class Solution {
public:
    void search(vector<int>& nums, int& mn, int l, int r) {
        if (l > r)
            return;
        int mid = (l + r) / 2;

        mn = min(mn, nums[mid]);
        if (nums[mid] >= nums[0]) {
            search(nums, mn, mid + 1, r);
        } else {
            search(nums, mn, l, mid - 1);
        }
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int res = nums[(n - 1) / 2];
        search(nums, res, 0, n - 1);
        return min(res, nums[0]);
    }
};