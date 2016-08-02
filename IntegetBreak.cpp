// looked forum
// https://discuss.leetcode.com/topic/43055/why-factor-2-or-3-the-math-behind-this-problem
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) {
            return 1;
        }
        
        if (n == 3) {
            return 2;
        }
        
        int product = 1;
        while (n > 4) {
            product *= 3;
            n -= 3;
        }
        product *= n; // the left n could be 2,3,4
        return product;
    }
};