class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        int N = nums.size();
        sort(nums.begin(), nums.end());
        for (int k = 0; k < N; k++) {
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k - 1]) continue; // Reduce duplicates - only find a result once per value

            int l = k + 1, r = N - 1;
            while (l < r) {
                int sum = nums[l] + nums[r] + nums[k];
                if (sum > 0) r--;
                else if (sum < 0) l++;
                else {
                    output.push_back({nums[l], nums[r], nums[k]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                }
            }
        }
        return output;
    }
};
