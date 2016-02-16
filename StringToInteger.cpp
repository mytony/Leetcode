// 1
class Solution {
public:
    int myAtoi(string str) {
        long num = 0;
        bool isPos = true;
        unsigned i = 0;
        while(i < str.length() && str[i] == ' '){
            i++;
        }
        if(i == str.length()){
            return 0;
        } else if (str[i] != '+' && str[i] != '-' && !isdigit(str[i])){
            return 0;
        } else if (!isdigit(str[i])){
            if(str[i] == '-'){
                isPos = false;
            }
        } else {
            num = num * 10 + (str[i] - '0');
        }
        i++;
        while(i < str.length() && isdigit(str[i])){
            num = num * 10 + (str[i] - '0');
            if(num > INT_MAX) // 防止long爆掉
                break;
            i++;
        }
        if(isPos)
            return (num > INT_MAX)?INT_MAX:num;
        else
            return (-num < INT_MIN)?INT_MIN:-num;
    }
};
