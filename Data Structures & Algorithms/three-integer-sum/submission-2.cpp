class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        set<vector<int>> intermediate;
        sort(nums.begin(), nums.end());
        int k = 0;
        int N = nums.size();
        while (k < N) {
            // i, j
            // nums[i] + nums[j] = -nums[k]
            int target = nums[k] * -1;
            // nums[i] + nums[j] = target
            int i = 0, j = nums.size() - 1;
            while (i < j) {
                if (i == k) {
                    i++;
                    continue;
                }
                if (j == k) {
                    j--;
                    continue;
                }
                if (nums[i] + nums[j] < target) {
                    i++;
                }
                else if (nums[i] + nums[j] > target) {
                    j--;
                }
                else {
                    vector<int> triplet;
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[j]);
                    triplet.push_back(nums[k]);
                    sort(triplet.begin(), triplet.end());
                    intermediate.insert(triplet);
                    i++;
                    j--;
                }
            }
            k++;
        }
        for (const auto& triplet : intermediate) {
            output.push_back(triplet);
        }
        return output;
    }
};
