class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (const auto& num : nums) {
            freq[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (const auto& elem : freq) {
            heap.push({elem.second, elem.first});
            if (heap.size() > k) {
                heap.pop();
            }
        }
        vector<int> output;
        for (int i = 0; i < k; i++) {
            output.push_back(heap.top().second);
            heap.pop();
        }
        return output;
    }
};
