class Solution {
public:
    // Use two pointers to track each vowel for both side
    // Then swap them until they are the same
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < s.size() && !isVowel(s[left])) {
                left++;
            }
            while (right >=0 && !isVowel(s[right])) {
                right--;
            }
            if (left >= right)  break;
            if (s[left] != s[right]) {
                char tmp = s[left];
                s[left] = s[right];
                s[right] = tmp;
            }
            left++; 
            right--;
        }
        return s;
    }
    
    bool isVowel(char c) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || 
            c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }
};