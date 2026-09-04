class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // prefixMult[i] = nums[0] * nums[1] * ... * nums[i - 1]
        // suffixMult[i] = nums[i + 1] * nums[i + 2] * ... * nums[N]
        // prefixMult[0] = 1; suffixMult[N] = 1;
        int N = nums.size() - 1;
        vector<int> prefixMult, suffixMult;
        for (int i = 0; i <= N; i++) {
            prefixMult.push_back(0);
            suffixMult.push_back(0);
        }
        prefixMult[0] = 1;
        suffixMult[N] = 1;
        for (int i = 1; i <= N; i++) {
            prefixMult[i] = prefixMult[i - 1] * nums[i - 1];
        }
        for (int i = N - 1; i >= 0; i--) {
            suffixMult[i] = suffixMult[i + 1] * nums[i + 1];
        }
        for (int i = 0; i <= N; i++) {
            nums[i] = prefixMult[i] * suffixMult[i];
        }
        return nums;
    }
};
