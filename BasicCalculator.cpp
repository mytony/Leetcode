class Solution {
public:
    int calculate(string s) {
        stack<string> stack;
        int sum, num, i = 0;
        while(i < s.size()){
            char c = s[i];
            if(c == '(' || c == '+' || c == '-'){
                stack.push(string(1, c));
            } else if(isdigit(c)){
                int end = i+1;
                while(isdigit(s[end]) && end < s.size()){
                    ++end;
                }
                stack.push(s.substr(i, end-i));
                i = end;
                continue;
            } else if(c == ')'){
                sum = 0;
                while(stack.top() != "(") {
                    if(stack.top() == "+" || stack.top() == "-"){
                        if(stack.top() == "-"){
                            num *= -1;
                        }
                        stack.pop();
                        sum += num;
                    } else {
                        num = stoi(stack.top());
                        stack.pop();
                        if(stack.top() == "("){ // when number without sign follows '(' immediately
                            sum += num;
                        }
                    }
                }
                stack.pop();
                stack.push(to_string(sum));
            }
            ++i;
        } // end of while(i < s.size())
        sum = 0;
        while(!stack.empty()){
            if(stack.top() == "+" || stack.top() == "-"){
                if(stack.top() == "-"){
                    num *= -1;
                }
                stack.pop();
                sum += num;
            } else {
                num = stoi(stack.top());
                stack.pop();
                if(stack.empty()){ // when number without sign follows '(' immediately
                    sum += num;
                }
            }
        }
        return sum;
    }
};
