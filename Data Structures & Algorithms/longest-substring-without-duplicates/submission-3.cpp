class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int output = 0;
        int delta = 0;
        
        unordered_map<char, int> idxs;
        for (int i = 0; i < s.size(); i++) {
            if (idxs.contains(s[i])) {
                delta = max(idxs[s[i]], delta);
            }
            idxs[s[i]] = i + 1;
            output = max(output, idxs[s[i]] - delta);
        }
        return output;
    }
};
