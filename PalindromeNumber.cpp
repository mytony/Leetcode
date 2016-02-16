class Solution {
public:
    // x could be negative
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        } else if(x < 10){
            return true;
        }
        unsigned numDigits = 0;
        int num = x;
        // how many digits
        while(num != 0){
            ++numDigits;
            num /= 10;
        }
        num = x;
        int head, tail;
        while(num != 0){
            head = num / pow(10, numDigits-1);
            tail = num % 10;
            if(head != tail){
                return false;
            }
            // cut head and tail
            num = ( num % (int)pow(10, numDigits-1) ) / 10;
            numDigits -= 2;
        }
        return true;
        
    }
};
