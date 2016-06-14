class Solution {
public:
    int numSol = 0;
    vector<string> cur;
    
    int totalNQueens(int n) {
         // initial n string full of '.'
        cur.assign(n, string(n, '.'));
        // start to make a choice for first row
        backtrack(n, 0);
        return numSol;
    }
    
    void backtrack(int n, int row) {
        if (row == n) {
            numSol++;
            return;
        }
        
        // for every possible column for this row
        // put Q and go to next row
        for (int i = 0; i < n; i++) {
            if (validPlace(n, row, i)) {
                cur[row][i] = 'Q';
                backtrack(n, row+1);
                cur[row][i] = '.';
            }
        }
    }
    
    // check if (row, col) is a valid place
    bool validPlace(int n, int row, int col) {
        // don't need to check row because we won't have conflict row situation

        for (int i = 0; i < n; i++) {
            // column direction
            if (cur[i][col] == 'Q') {
                return false;
            }
            // check / direction (x+y would be fixed)
            if (row+col-i >= 0 && row+col-i < n && cur[i][row+col-i] == 'Q') {
                return false;
            }
            // check \ direction (x and y would both +/- 1) (x-y is fixed)
            if (i+col-row >=0 && i+col-row < n && cur[i][i+col-row] == 'Q') {
                return false;
            }
        }
        
        return true;
    }
};