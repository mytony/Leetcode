class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0)  return 0;
        // cut off tailing spaces
        while (s[s.size()-1] == ' ') {
            s.erase(s.size()-1);
        }
        size_t lastSpace = s.find_last_of(' ');
        if (lastSpace == string::npos) {
            return s.size();
        } else {
            return s.substr(lastSpace+1).size();
        }
    }
};