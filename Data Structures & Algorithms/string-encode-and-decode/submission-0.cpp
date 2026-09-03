class Solution {
public:
    string encode(vector<string>& strs) {
        string output = "";
        for (const string& str : strs) {
            output += to_string(str.size()) + ":" + str;
        }
        return output;
    }

    vector<string> decode(string s) {
        vector<string> output;
        string str = "";
        int N = s.size(), i = 0;
        while (i < N) {
            int word_len = 0;
            while (s[i] != ':') {
                str += s[i++];
            }
            word_len = stoi(str);
            str = "";
            i++;
            while (word_len-- > 0) {
                str += s[i++];
            }
            output.push_back(str);
            str = "";
        }
        return output;
    }
};
