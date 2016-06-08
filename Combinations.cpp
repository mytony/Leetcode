class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 0);
        return res;
    }
    
    void backtrack(int n, int k, int pos) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }
        for (int i = pos; i < n; i++) {
            cur.push_back(i+1);
            backtrack(n, k, i+1);
            cur.pop_back();
        }
    }
};