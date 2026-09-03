class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hash;
        // O(n) build hashmap
        for (int num : nums) {
            hash[num]++;
        }
        int max_seq = 0;
        vector<int> potential;
        // O(n) find potential sequence heads
        for (const auto& [key,val] : hash) {
            if (!hash.contains(key - 1)) {
                potential.push_back(key);
            }
        }
        // This will only run at most O(n) times.
        for (const auto& elem : potential) {
            int len = 1;
            int curr = elem;
            while (hash[curr + 1] != 0) {
                len++;
                curr++;
            }
            max_seq = max(max_seq, len);
        }
        // Total O(n) runtime, O(n) space
        return max_seq;
    }
};
