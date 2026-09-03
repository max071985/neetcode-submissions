class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> chars(26, 0);
        for (const char c : s)
            chars[c - 'a']++;
        for (const char c : t)
            chars[c - 'a']--;
        for (const int i : chars) {
            if (i != 0) return false;
        }
        return true;
    }
};
