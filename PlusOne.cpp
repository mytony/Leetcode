class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        if(digits[size-1] < 9){
            digits[size-1]++;
        } else {
            int i = size-1;
            do{
                if(i == 0){
                    digits.insert(digits.begin(), 0);
                    i++;
                }
                digits[i] = 0;
                digits[i-1]++;
                i--;
            } while (digits[i] == 10);
        }
        return digits;
    }
};
