class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size(), product0 = 1;
        vector<int> results(N, 1);
        for (int i = 1; i < N; i++) {
            product0 *= nums[i];
        }
        results[0] = product0;
        for (int i = 1; i < N; i++) {
            if (nums[i] == 0) {
                int prod = 1;
                for (int j = 0; j < N; j++) {
                    if (j != i) prod *= nums[j];
                }
                results[i] = prod;
            }
            else
                results[i] = (results[i - 1] / nums[i]) * nums[i - 1];
        }
        return results;
    }
};
