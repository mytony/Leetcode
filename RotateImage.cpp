// looked forum
// https://leetcode.com/discuss/20589/a-common-method-to-rotate-the-image
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < i+1; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};