class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0, end = s.size() - 1;
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        while (front < end) {
            while (front < s.size() && !isalnum(s[front]))  front++;
            while (end >= 0 && !isalnum(s[end]))    end--;
            if (front < end && s[front] != s[end]) {
                return false;
            }
            front++;
            end--;
        }
        return true;
    }
};