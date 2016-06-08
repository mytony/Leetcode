class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0};
        unordered_set<int> set = {0};
        return backtrack(n, 1, set, res);
    }
    
    vector<int> backtrack(int n, int pre, unordered_set<int>& set, vector<int>& res) {
        if (res.size() == pow(2, n)) return res;
        for (int i = 0; i < n; i++) {
            if (i != pre) {
                int tmp = res[res.size()-1];
                tmp = tmp ^ (1 << i);
                if (set.find(tmp) != set.end()) continue;
                res.push_back(tmp);
                set.insert(tmp);
                return backtrack(n, i, set, res);
            }
        }
        return {0};
    }
};

// 89. 行為怪異，不知道為何n=0的時候k會接到0
// class Solution {
// public:
//     vector<int> grayCode(int n) {
//         cout << (2 << 1) << endl;
//         cout << (2 << 0) << endl;
//         cout << (2 << -1) << endl;
//         cout << "n" << n << endl;
//         vector<int> res = {0};
//         return backtrack((2 << (n-1)), 1, res);
//     }
    
//     vector<int> backtrack(int k, int pos, vector<int>& res) {
//         cout << res.size() << endl;
//         cout << "k" << k << endl;
//         if (res.size() == k)
//             return res;
//         for (int i = pos; i < k; i++) {
//             res.push_back(i);
//             backtrack(k, i+1, res);
//             res.pop_back();
//         }
//         return {};
//     }
// };