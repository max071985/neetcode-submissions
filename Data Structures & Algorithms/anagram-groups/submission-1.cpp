class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        unordered_map<string, vector<string>> anagrams;
        int N = strs.size();
        for (int i = 0; i < N; i++) {
            string sortedElem = strs[i];
            sort(sortedElem.begin(), sortedElem.end());
            if (anagrams.find(sortedElem) == anagrams.end()) {
                vector<string> anagVal = {strs[i]};
                anagrams.insert({sortedElem, anagVal});
            }
            else {
                anagrams[sortedElem].push_back(strs[i]);
            }
        }
        for (const auto& [key, value] : anagrams) {
            output.push_back(value);
        }
        return output;
    }
};
