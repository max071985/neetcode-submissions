class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash;
        for (const auto& c : s) {
            hash[c]++;
        }
        for (const auto& c : t) {
            hash[c]--;
        }
        for (const auto& [key, val]: hash) {
            if (val != 0) return false;
        }
        return true;
    }
};
