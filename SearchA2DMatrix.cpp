class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        
        int start = 0, end = matrix.size()-1, mid;
        // first find which row
        while (start <= end) {
            mid = (start + end) / 2;
            if (target == matrix[mid][0]) return true;
            if (target < matrix[mid][0]) {
                if (mid == 0) return false; // it's first row
                end = mid - 1;
            }
            if (target > matrix[mid][0]) {
                if (mid == matrix.size()-1) break; // it's last row
                if (target < matrix[mid+1][0]) break;
                start = mid + 1;
            }
        }
        
        // search element on that row
        int row = mid;
        start = 0, end = matrix[row].size() - 1;
        
        while (start <= end) {
            mid = (start + end) / 2;
            if (target == matrix[row][mid]) return true;
            if (target < matrix[row][mid]) end = mid - 1;
            if (target > matrix[row][mid]) start = mid + 1;
        }
        return false;
    }
};