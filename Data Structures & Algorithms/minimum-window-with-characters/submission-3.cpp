class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_occurances;
        unordered_map<char, int> w_occurances;
        int t_unique = 0, w_unique = 0;

        for (char c : t) {
            t_occurances[c]++;
            if (t_occurances[c] == 1) t_unique++;
        }
        int l = 0, r = 0;
        int minL = -1, minR = s.size() - 1;
        while (l < s.size()) {
            if (w_unique == t_unique) {
                if (r - l - 1 < minR - minL) {
                    minL = l;
                    minR = r - 1;
                }
                w_occurances[s[l]]--;
                if (w_occurances[s[l]] < t_occurances[s[l]]) w_unique--;
                l++;
            }
            else {
                if (r == s.size()) break;
                w_occurances[s[r]]++;
                if (w_occurances[s[r]] == t_occurances[s[r]]) w_unique++;
                r++;
            }
        }
        if (minL == -1) return "";
        return s.substr(minL, minR - minL + 1);
    }
};
