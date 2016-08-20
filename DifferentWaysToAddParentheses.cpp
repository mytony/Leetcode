// looked forum
// https://leetcode.com/discuss/48488/c-4ms-recursive-%26-dp-solution-with-brief-explanation
class Solution {
private:
    // use memoization to avoid duplicate calculation
    unordered_map<string, vector<int>> memo;
public:
    vector<int> diffWaysToCompute(string input) {
        if (memo.find(input) != memo.end()) { return memo[input]; }
        
        vector<int> res;
        for (int i = 0; i < input.size(); i++) {
            char c = input[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> result1 = diffWaysToCompute(input.substr(0, i));
                vector<int> result2 = diffWaysToCompute(input.substr(i+1));
                
                for (int n1: result1) {
                    for (int n2: result2) {
                        if (c == '+')
                            res.push_back(n1 + n2);
                        else if (c == '-')
                            res.push_back(n1 - n2);
                        else
                            res.push_back(n1 * n2);  
                    }
                }
            }
        }
        
        // input string only contains a number
        if (res.empty()) {
            res.push_back(stoi(input));
        }
        
        memo[input] = res;
        return res;
    }
    
    // I tried to search by regex
    // vector<string> split(string input) {
    //     regex re("(-?\d+)([+-*])(-?\d+)");
    //     smatch sm;
    //     string::const_iterator searchStart(input.cbegin());
    //     while (regex_search(searchStart, input.cend(), sm, re)) {
    //         for (auto x: sm) cout << x;
    //         cout << endl;
    //         searchStart += sm.position() + sm.length();
    //     }
    //     return {};
    // }
    
    // void helper(string input, vector<int>& res) {
    //     // save the result if the string is only a number
    //     if (isNumber(input)) {
    //         res.push_back(stoi(input));
    //         return;
    //     }
        
    //     // split the string into three parts:
    //     // before, middle, after. The middle one is for to process
    // } 
    
    // check the negative number too
    // bool isNumber(string s) {
    //     for (int i = 0; i < s.size(); i++) {
    //         char c = s[i];
    //         if (c == '+' || c == '*')   return false;
    //         if (c == '-' && i != 0) return false;
    //     }
    //     return true;
    // }
};