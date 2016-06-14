class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int a, b;
        vector<int> res(rowIndex+1, 1);
        
        // skip first two row full of 1
        for (int i = 3; i <= rowIndex+1; i++) {
            a = 1, b = res[1];
            // skip first and last element, which are 1
            for (int j = 1; j < i-1; j++) {
                res[j] = a + b;
                a = b;
                b = res[j+1];
            }
        }
        return res;
    }
};