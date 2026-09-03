// O(n) time, O(n) space hashmap approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> hash; // Store <value, first_index_occurance> pairs
        vector<int> output;
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            hash[nums[i]].push_back(i);
            if (hash.contains(target - nums[i])) {
                int min_idx = N;
                for (int idx : hash[target - nums[i]]) {
                    min_idx = min(min_idx, idx);
                }
                if (min_idx != i) {
                    output.push_back(min(min_idx, i));
                    output.push_back(max(min_idx, i));
                    return output;
                }
            }
        }
        return output;
    }
};
