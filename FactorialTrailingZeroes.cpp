class Solution {
public:
    int trailingZeroes(int n) {
        int k = 1;
        int num = 0;
        int count;
        while((count = n / pow(5, k)) != 0){
            num += count;
            k++;
        }
        return num;
    }
};
