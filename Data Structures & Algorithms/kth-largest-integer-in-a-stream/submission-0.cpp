class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> mh;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if (mh.size() < k) {
            mh.push(val);
        }
        else {
            if (val > mh.top()) {
                mh.pop();
                mh.push(val);
            }
        }
        return mh.top();
    }
};
