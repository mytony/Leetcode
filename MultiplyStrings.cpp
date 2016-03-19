class Solution {
    public:
        // given two integer strings, output their multiplication in string
        string multiply(string num1, string num2) {
            string rst(num1.size() + (num2.size() - 1) + 1, '0'); // larget possibe size of result
            for (int i = num1.size() - 1; i >= 0; i--) {
                for (int j = num2.size() - 1; j >= 0; j--) {
                    int tmp = (num1[i] - '0') * (num2[j] - '0');
                    int k = i + j + 1; // if num is 10, 0 should be put at index k
                    int sign = 0;
                    int col = 0; // each column addition result
                    while (tmp != 0) {
                        col = rst[k] + tmp % 10 + sign;
                        if (col > '9') {
                            col -= 10;
                            sign = 1;
                        } else {
                            sign = 0;
                        }
                        rst[k] = col;
                        tmp /= 10;
                        k--;
                    }
                    // keep adding 1 backward until no sign
                    while (sign) {
                        col = rst[k] + sign;
                        if (col > '9') {
                            rst[k] = col - 10;
                        } else {
                            rst[k] = col;
                            sign = 0;
                        }
                        k--;
                    }
                }
            }
            rst.erase(0, min(rst.find_first_not_of('0'), rst.size() - 1));
            return rst;
        }
};
