class Solution {
public:
    bool wordPattern(string pattern, string str) {
        // Because str must be non-empty
        if (pattern.size() == 0) {
            return false;
        }
        
        unordered_map<char, string> mapA;
        unordered_map<string, char> mapB;
        
        size_t start = 0, pos;
        string word;
        
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            
            // cut a word from str
            pos = str.find(' ', start);
            if (pos == string::npos) {
                // pattern is more than words
                if (i != pattern.size() - 1) {
                    return false;
                }
                word = str.substr(start);
            } else {
                word = str.substr(start, pos-start);
            }
            start = pos + 1;
            
            // if a character or word already been connected but the other is not
            if ( mapA.find(c) == mapA.end() ^ 
                 mapB.find(word) == mapB.end() ) {
                return false; 
            }
            
            if (mapA.find(c) == mapA.end()) {
                mapA[c] = word;
                mapB[word] = c;
            } else {
                // check consistency
                if (mapA[c] != word || mapB[word] != c) {
                    return false;
                }
            }
        }
        
        // words are more than pattern
        if (pos != string::npos) {
            return false;
        }
        return true;
    }
};