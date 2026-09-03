class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> chars;
        const int N = s.size();
        int l = 0, delta = 0, output = 0;
        for (int r = 0; r < N; r++) {
            chars[s[r]]++;
            delta = max(delta, chars[s[r]]);
            while ((r - l + 1) - delta > k) {
                chars[s[l]]--;
                l++;
            }
            output = max(output, (r - l + 1));
        }
        return output;
    }
};
