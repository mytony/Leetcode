// https://leetcode.com/discuss/38997/detailed-explained-8ms-c-solution
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend > 0) ^ (divisor > 0)) ? -1 : 1;
        long dvd = abs((long)dividend); // can use labs() or abs(long int)
        long dvs = abs((long)divisor); // 加long是因為INT_MIN轉正會爆掉
        int res = 0;
        while(dvd >= dvs){
            long tmp = dvs;
            long multiple = 1;
            while(dvd >= (tmp << 1)){
                tmp <<= 1;
                multiple <<= 1;
            }
            dvd -= tmp;
            res += multiple;
        }
        return sign == 1 ? res : -res;
    }
};
