// looked forum
// my original solution used for loop and ends up TLE
class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0) return a;
        int tmpSum = a ^ b; // sum of each bit
        int carry = (a & b) << 1; // carry of each bit
        return getSum(tmpSum, carry);
    }
};