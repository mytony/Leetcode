class Solution {
public:
    // when r = 1, the string is same
    // for other numbers of rows, the first row and last row
    // will not change the step. For middle rows, step is changing
    string convert(string s, int numRows) {
        if (numRows == 1)   return s;
        
        string res = "";
        for (int i = 0; i < numRows; i++) {
            int j = i;
            int step = 2 * (numRows - 1 - i); // initial step
            int totalStep = 2 * (numRows - 1);
            // special pattern for last row
            if (i == numRows - 1) {
                step = 2 * (numRows - 1);
            }
            
            while (j < s.size()) {
                res += s[j];
                j += step;
                if (i != 0 && i != numRows - 1) {
                    step = totalStep - step;
                }
            }
        }
        return res;
    }
};