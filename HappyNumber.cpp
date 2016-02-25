// Another cool answer: https://leetcode.com/discuss/33055/my-solution-in-c-o-1-space-and-no-magic-math-property-involved
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> ht;
        ht.insert(n);
        while(n != 1){
            // run through every digit to calculate next number
            int tmp = 0;
            while(n != 0){
                int digit = n % 10;
                tmp += digit * digit;
                n /= 10;
            }
            n = tmp;
            if(ht.find(n) != ht.end()){ // If repeat
                return false;
            } else {
                ht.insert(n);
            }
        }
        return true;
    }
};
