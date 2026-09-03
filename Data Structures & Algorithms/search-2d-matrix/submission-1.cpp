class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // traverse rows first to find a row whos first element is greater than the target
        int rows = matrix.size() - 1;
        int l = 0, r = rows;
        int row = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] <= target && target <= matrix[mid][matrix[0].size() - 1]) {
                row = mid; // Target belongs in this row
                break;
            }
            else if (matrix[mid][0] > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        if (row < 0) return false;
        l = 0;
        r = matrix[row].size() - 1;
        // traverse the row
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] > target) {
                r = mid - 1;
            }
            else if (matrix[row][mid] < target) {
                l = mid + 1;
            }
        }
        return false;
    }
};
