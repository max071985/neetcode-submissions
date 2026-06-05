class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (hash.find(nums[i]) == hash.end())
                hash.insert({nums[i], 1});
            else
                return true;
        }
        return false;
    }
};