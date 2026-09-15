class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxL = height[l], maxR = height[r];
        int output = 0;
        while (l < r) {
            if (maxL < maxR) {
                l++;
                maxL = max(maxL, height[l]);
                output += maxL - height[l];
            }
            else {
                r--;
                maxR = max(maxR, height[r]);
                output += maxR - height[r];
            }
        }
        return output;
    }
};
