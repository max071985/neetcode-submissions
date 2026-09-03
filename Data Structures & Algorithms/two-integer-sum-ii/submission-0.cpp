class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        vector<int> output;
        while (l < r) {
            if (numbers[l] + numbers[r] < target) {
                l++;
            }
            else if (numbers[l] + numbers[r] > target) {
                r--;
            }
            else {
                output.push_back(l+1);
                output.push_back(r+1);
                return output;
            }
        }
        return output;
    }
};
