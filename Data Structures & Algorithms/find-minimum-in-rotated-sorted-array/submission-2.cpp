class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        int m = 1000;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int tmp = min(nums[l], nums[r]);
            tmp = min(tmp, nums[mid]);
            m = min(m, tmp);
            if (nums[l] <= nums[r]) {
                return m;
            }
            else if (nums[l] <= nums[mid]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return m;
    }
};
