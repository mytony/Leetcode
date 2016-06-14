// looked forum
// https://leetcode.com/discuss/48852/my-concise-o-m-n-java-solution
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        int row = 0, col = n - 1;
        
        while (row < m && col >= 0) {
            int top_right = matrix[row][col];
            
            if (top_right == target)    return true;
            else if (top_right > target)    col--;
            else    row++;
        }
        
        return false;
    }
};