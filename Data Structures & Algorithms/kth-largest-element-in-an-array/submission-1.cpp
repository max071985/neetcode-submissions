class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-Heap of size k;
        // Time Complexity: O(nlgn)
        // Space COmp. O(k)
        priority_queue<int, vector<int>, greater<int>> mh;
        for (auto num : nums) {
            if (mh.size() >= k) {
                if (num > mh.top()) {
                    mh.pop();
                    mh.push(num);
                }
            }
            else {
                mh.push(num);
            }
        }
        return mh.top();
    }
};
