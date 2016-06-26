class Solution {
public:
    // 規律是前兩者相加
    int climbStairs(int n) {
        if (n < 3) return n;
        int f1 = 1;
        int f2 = 2;
        for (int i = 2; i < n; i++) {
            int sum = f1 + f2;
            f1 = f2;
            f2 = sum;
        }
        return f2;
    }
};