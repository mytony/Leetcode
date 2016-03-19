class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1) {
            return 1;
        }
        
        bool flip = false;
        bool max = false;
        
        if (n < 0) {
            flip = true;
            // special case
            if (n == INT_MIN) {
                n = INT_MAX;
                max = true;
            } else {
                n = abs(n);
            }
        }
        
        double result = 1;
        double current = x;
        
        // split multiplication into multiply of 2, x^1, x^2, x^4..
        while (n != 0) {
            if (n & 1) {
                result *= current;
            }
            n = n >> 1;
            current *= current;
        }
        if (max) {
            result *= x;
        }
        return flip ? 1 / result : result;
    }
};
