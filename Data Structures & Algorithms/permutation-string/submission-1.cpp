class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        int test_freq[26] = {0};
        int counter = 0;
        int test_counter = 0;
        int N = s1.size();
        int M = s2.size();
        if (N > M) return false;
        for (char c : s1) {
            freq[(int)(c - 'a')]++;
            counter++;
        }
        int l = 0;
        for (int r = 0; r < M; r++) {
            if (r - l + 1 > N) {
                test_freq[s2[l] - 'a']--;
                if (test_freq[s2[l] - 'a'] < freq[s2[l] - 'a']) {
                    test_counter--;
                }
                l++;
            }
            test_freq[s2[r] - 'a']++;
            if (test_freq[s2[r] - 'a'] <= freq[s2[r] - 'a']) test_counter++;
            if (test_counter == counter) return true;
        }
        return test_counter == counter;
    }
};
