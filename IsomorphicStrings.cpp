class Solution {
public:
    // There could be any characters so I use unordered_map but not vector
    bool isIsomorphic(string s, string t) {
        char a, b;
        unordered_map<char, char> mapA, mapB;
        
        for (int i = 0; i < s.size(); i++) {
            a = s[i];
            b = t[i];
            
            // one of them already been assigned
            if (mapA.find(a) == mapA.end() ^ mapB.find(b) == mapB.end()) {
                return false;
            }
            
            
            if (mapA.find(a) == mapA.end()) { // both are not assigned
                mapA[a] = b;
                mapB[b] = a;
            } else { // both are assigned
                // check consistency
                if (mapA[a] != b || mapB[b] != a) {
                    return false;
                }
            }
        }
        return true;
    }
};