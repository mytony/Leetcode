class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int sum = 0;
        int nums = 0;
        
        if (n == 0) return 1; // only 0
        
        // 從一位數到n位數
        sum += 10; // 一位數
        nums = 9; // 排列組合的數: 2 digits, 9*9. 3 digits, 9*9*8
        for (int i = 2; i <= n; i++) {
            nums *= 11 - i; // *9 for 2 digits, *8 for 3 digits
            sum += nums;
        }
        
        return sum;
    }
};