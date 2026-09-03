class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        unordered_map<string, vector<int>> anagrams;
        int N = strs.size();
        for (int i = 0; i < N; i++) {
            string sortedElem = strs[i];
            sort(sortedElem.begin(), sortedElem.end());
            if (anagrams.find(sortedElem) == anagrams.end()) {
                vector<int> idxs = {i};
                anagrams.insert({sortedElem, idxs});
            }
            else {
                anagrams[sortedElem].push_back(i);
            }
        }
        for (const auto& [key, idxs] : anagrams) {
            vector<string> originalStrs;
            for (int idx : idxs)
                originalStrs.push_back(strs[idx]);
            output.push_back(originalStrs);
        }
        return output;
    }
};
