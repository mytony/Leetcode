class Solution {
public:
    // 規律：第一條線跑n個，剩下每兩條跑n-1，接著n-2...直到1
    // 但這題不是n*n，如果是1*2的，for迴圈會判斷有誤
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int r = 0, c = 0;
        int numLines = 1;
        int m = matrix.size(), n;
        if (m == 0) return res;
        n = matrix[0].size();
        
        while (res.size() < m*n) {
            for (int i = 0; i < (n - numLines / 2); i++) {
                res.push_back(matrix[r][c++]);
            }
            c--; r++; numLines++;
            
            for (int i = 0; i < (m - numLines / 2); i++) {
                if (res.size() < m*n)
                    res.push_back(matrix[r++][c]);
            }
            r--; c--; numLines++;
            
            for (int i = 0; i < (n - numLines / 2); i++) {
                if (res.size() < m*n)
                    res.push_back(matrix[r][c--]);
            }
            c++; r--; numLines++;
            
            for (int i = 0; i < (m - numLines / 2); i++) {
                if (res.size() < m*n)
                    res.push_back(matrix[r--][c]);
            }
            r++; c++; numLines++;
        }
        
        return res;
    }
};