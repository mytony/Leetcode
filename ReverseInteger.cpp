class Solution {
public:
    int reverse(int x) {
        if(x > -10 && x < 10)   return x;
        // Turn negative number to positive
        bool isNeg = false;
        if(x < 0){
            isNeg = true;
            x = -x;
        }
        // Get number of digits
        int numDigits = 0;
        ////////////// the result of pow() is double /////////////
        while(x / (int)pow(10, numDigits) > 0){
            numDigits++;
        }
        // Reverse number
        long revNum = 0;
        for(int i = numDigits-1; i >= 0; i--){
            int num = (x / (int)pow(10, i));
            x -= num * pow(10, i);
            revNum +=  num * (long)pow(10, (numDigits - i - 1)); // 等號右邊有辦法存超過大於int的嗎，不行，要強迫轉成long
        }
        if(revNum > INT_MAX)    return 0;
        if(isNeg)   return -revNum;
        else    return revNum;
    }
};
