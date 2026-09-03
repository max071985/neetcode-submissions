class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        // find pivot
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        // found pivot
        int pivot = l;
        cout << pivot << "\n";
        int left = bs(nums, 0, pivot - 1, target);
        int right = bs(nums, pivot, nums.size() - 1, target);
        if (left != -1) return left;
        if (right != -1) return right;
        return -1;
    }

    int bs(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] <= target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return -1;
    }
};
