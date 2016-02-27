class Solution {
public:
    string mappings[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        vector<string> rst;
        decode(digits, 0, string(), rst);
        return rst;
    }
    
    void decode(string digits, int pos, string current, vector<string>& rst) {
        if(pos == digits.size()){
            if(!current.empty()){
                rst.push_back(current);
            }
            return;
        }
        if(digits[pos] < '2'){
            return;
        }
        string choices = mappings[digits[pos] - '2'];
        for(int j = 0; j < choices.size(); j++){
            decode(digits, pos + 1, current + choices[j], rst);
        }
    }
};
