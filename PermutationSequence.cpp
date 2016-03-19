class Solution {
public:
    string getPermutation(int n, int k) {
        int group = 1;
        bool num[n];
        // initialize array
        for (int i = 0; i < n; i++) {
            num[i] = true;
        }
        // the initial divisor
        for (int i = 1; i < n; i++) {
            group *= i;
        }
        return permute(num, n, group, k, "");
    }
    string permute(bool *num, int len, int group, int k, string str) {
        int first = (k - 1) / group;
        int count = 0;
        
        for (int i = 0; i < len; i++) {
            if (num[i]) {
                if (count == first) {
                    num[i] = false;
                    str += ('0' + i + 1);
                    break;
                }
                count++;
            }
        }
        
        // stop case
        if (str.size() == len) {
            return str;
        }

        k -= first * group;
        group /= (len - str.size());
        return permute(num, len, group, k, str);
    }
};
