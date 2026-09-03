class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int output = r;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long t = 0;
            for (int p : piles) {
                t += ceil(static_cast<double>(p) / mid);
            }
            if (t <= h) {
                output = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return output;
    }
};
