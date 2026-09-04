class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // nums = [1, 2, 3]
        // output[0] = output[1] * output[2] = 2*3 = 1*2*3 / 1
        int32_t totalMult = 1;
        int zeroCnt = 0;
        for (auto num : nums) {
            if (num == 0) {
                zeroCnt++;
            }
            else {
                totalMult *= num;
            }
        }
        if (zeroCnt > 1) totalMult = 0;
        for (auto& num : nums) {
            if (zeroCnt > 0) {
                if (num == 0) {
                    num = totalMult;
                }
                else {
                    num = 0;
                }
            }
            else {
                num = totalMult / num;
            }
        }
        return nums;
    }
};
