class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res (n, vector<int>(n, 0));
        int r = 0, c = 0;
        int count = 1;
        
        if (n == 0) return res;
        // while迴圈的條件要什麼好呢？
        // 倒數n^2次，還是直到遇到不是0
        // while (res[r][c] == 0) { // cannot handle n = 1
        while (count <= pow(n, 2)) {
            // 怎麼控制四個方向？
            // 用for迴圈直到邊界
            // 但是怎麼結束？
            while (c < n && res[r][c] == 0) {
                res[r][c] = count;
                count++;
                c++;
            }
            c--;
            r++;
            while (r < n && res[r][c] == 0) {
                res[r][c] = count;
                count++;
                r++;
            }
            r--;
            c--;
            while (c >= 0 && res[r][c] == 0) {
                res[r][c] = count;
                count++;
                c--;
            }
            c++;
            r--;
            while (r >= 0 && res[r][c] == 0) {
                res[r][c] = count;
                count++;
                r--;
            }
            r++;
            c++;
        }
        return res;
    }
};