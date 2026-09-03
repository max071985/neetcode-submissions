class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for (const auto& str : strs) {
            vector<int> arr(26, 0);
            for (char c : str) {
                arr[c - 'a']++;
            }
            string key = to_string(arr[0]);
            for (int i = 1; i < 26; i++) {
                key += ',' + to_string(arr[i]);
            }
            anagrams[key].push_back(str);
        }
        vector<vector<string>> output;
        for (const auto& [key, value] : anagrams) {
            output.push_back(value);
        }
        return output;
    }
};
