class Solution {
public:
    void searchInfliction(vector<int>& nums, int& mn, int& indx, int l, int r) {
        if (l > r)
            return;
        int mid = (l + r) / 2;
        if (mn > nums[mid]) {
            mn = nums[mid];
            indx = mid;
        }
        if (nums[0] <= nums[mid]) {
            searchInfliction(nums, mn, indx, mid + 1, r);
        } else {
            searchInfliction(nums, mn, indx, l, mid - 1);
        }
    }

    int binarySearch(vector<int>& nums, int& target, int l, int r) {
        if (l > r)
            return -1;
        int mid = (l + r) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;

        return binarySearch(nums, target, l, r);
    }

    int search(vector<int>& nums, int target) {
        int mn, indx, n, res;

        mn = nums[0];
        indx = 0;
        n = nums.size();

        searchInfliction(nums, mn, indx, 0, n - 1);

        res = binarySearch(nums, target, indx, n - 1);
        if (res != -1)
            return res;

        res = binarySearch(nums, target, 0, indx - 1);

        return res;
    }
};
