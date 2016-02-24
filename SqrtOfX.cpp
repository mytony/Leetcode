class Solution {
public:
    int mySqrt(int x) {
        // Idea: start from x/2, compare it's square and x, if smaller, change to a number during the middle of (x/2, x), and so on. 
        // Be aware that the square could be overflow.
        int low = 0;
        int high = x;
        long mid, sq;
        while(true){
            mid = low + (high - low) / 2; // a clever way to prevent overflow
            sq = mid * mid;
            if(sq > x){
                if(pow(mid - 1, 2) <= x)
                    return mid - 1;
                high = mid;
            } else if(sq < x){
                if(pow(mid + 1, 2) > x)
                    return mid;
                else if(pow(mid + 1, 2) == x)
                    return mid + 1;
                low = mid;
            } else {
                return mid;
            }
        }
    }
};
