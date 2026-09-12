class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Obvious easy solution, with O(n) time complexity and O(n) space complextiy
        unordered_map<int, int> hash;
        for (int num : nums) {
            hash[num]++;
            if (hash[num] == 2) return num;
        }
        return -1;
    }
};
