class Solution {
public:
    bool isValid(string s) {
        stack<char> left;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case ')':
                if (left.empty() || left.top() != '(')  return false;
                left.pop();
                break;
                case ']':
                if (left.empty() || left.top() != '[')  return false;
                left.pop();
                break;
                case '}':
                if (left.empty() || left.top() != '{')  return false;
                left.pop();
                break;
                default:
                left.push(s[i]);
            }
        }
        return left.empty() ? true:false;
    };
};