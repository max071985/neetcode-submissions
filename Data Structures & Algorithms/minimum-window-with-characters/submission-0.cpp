class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int> freq;
        unordered_map<char, int> tmp_freq;
        int min_count = 1000;
        string output = "";
        int N = s.size();
        int M = t.size();
        if (M > N) return "";
        int counter = 0;
        for (char c : t) {
            freq[c]++;
            counter++;
        }
        int tmp_counter = 0;
        bool flag = false;
        int l = 0;
        for (int r = 0; r < N; r++) {
            if (flag) {
                tmp_freq[s[l]]--;
                if (tmp_freq[s[l]] < freq[s[l]]) {
                    tmp_counter--;
                    flag = false;
                }
            }
            tmp_freq[s[r]]++;
            if (tmp_freq[s[r]] <= freq[s[r]]) tmp_counter++;
            if (!flag && tmp_counter == counter) {
                flag = true;
                while (flag) {
                    // move left
                    if (min_count > r - l + 1) {
                        min_count = r - l + 1;
                        output = s.substr(l, r - l + 1);
                    }
                    tmp_freq[s[l]]--;
                    if (tmp_freq[s[l]] < freq[s[l]]) {
                        tmp_counter--;
                        flag = false;
                    }
                    l++;
                    //cout << output << "\n";
                }
            }
        }
        if (min_count < M) return "";
        return output;
    }
};
