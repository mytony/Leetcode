// In forum, there's a solution using 3 bits to distinguish ACGT
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> map;
        
        for (int i = 0; i + 9 < s.size(); i++) {
            string str = s.substr(i, 10);
            map[str]++;
        }
        
        for (auto pair : map) {
            if (pair.second > 1) {
                res.push_back(pair.first);
            }
        }
        return res;
    }
};