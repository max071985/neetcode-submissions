class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        priority_queue<pair<int,int>> maxheap; // first: nums[i], second: i
        for (int i = 0; i < nums.size(); i++) {
            maxheap.push({nums[i], i});

            if (i >= k - 1) {
                while(maxheap.top().second <= i - k) {
                    maxheap.pop();
                }
                output.push_back(maxheap.top().first);
            }
        }
        return output;
    }
};
