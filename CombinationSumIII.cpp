class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n, 0);
        return res;
    }
    
    void backtrack(int k, int n, int pos) {
        if (n == 0 && cur.size() == k) {
            res.push_back(cur);
            return;
        }
        if (cur.size() >= k) return;
        
        for (int i = pos; i < 9; i++) {
            if (i + 1 > n) break;
            cur.push_back(i+1);
            backtrack(k, n-i-1, i+1);
            cur.pop_back();
        }
    }
};