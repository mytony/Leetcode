class Solution {
public:
    // Find each word forward from the string, 
    // write the word to the original end of original string
    // when all is done, erase original front part
    void reverseWords(string &s) {
        size_t n = s.size();
        size_t start, end;
        
        // skip beginning spaces
        start = s.find_first_not_of(' '); // string::npos
        
        while (start < n && start != string::npos) {
            // find the ending position of the word
            end = s.find(' ', start);
            s.insert(n, " " + s.substr(start, end - start));
            start = s.find_first_not_of(' ', end);
        }
        
        s.erase(0, n + 1); // 1 is for space
    }
};