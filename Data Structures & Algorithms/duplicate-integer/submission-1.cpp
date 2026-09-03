class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (const auto& num : nums) {
            hash[num]++;
            if (hash[num] > 1) return true;
        }
        return false;
    }
};