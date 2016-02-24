// 參考解答：https://leetcode.com/discuss/85529/very-easy-to-understand-java-solution-0ms-%E9%99%84%E4%B8%AD%E6%96%87%E8%A7%A3%E9%87%8A
class Solution {
public:
    int countDigitOne(int n) {
        int rearSize = 1;
        long mod = 1;
        int count = 0;
        while(mod <= n){
            long front = n / (mod * 10);
            long rear = n % mod;
            int curDigit =(int) (n % (mod * 10)) / rearSize;
    
            if(curDigit > 1){
                count += ((front + 1) * rearSize);
            }
            else if(curDigit == 1){
                count += (front * rearSize + rear + 1);
            }
            else{
                count += (front * rearSize);
            }
    
            mod *= 10;
            rearSize *= 10;
        }
        return count;
    }
};
