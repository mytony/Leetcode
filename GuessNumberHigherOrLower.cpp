// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1, hi = n, mi;
        while (true) {
            mi = lo + (hi - lo) / 2;
            int ans = guess(mi);
            
            if (ans == 0) {
                return mi;
            } else if (ans == 1) {
                lo = mi + 1;
            } else {
                hi = mi - 1;
            }
        }
    }
};