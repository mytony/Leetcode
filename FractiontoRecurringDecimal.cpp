class Solution {
public:
    // Reference:
    // https://leetcode.com/discuss/18731/accepted-cpp-solution-with-explainations
    string fractionToDecimal(int numerator, int denominator) {
        string result;
        unordered_map<int, int> map;
        long n = numerator, d = denominator; // prevent error caused by INT_MIN
        
        // numerator is zero
        if (!n) {
            return "0";
        }

        // concise way to check sign
        if (n < 0 ^ d < 0) {
            result += '-';
        }

        // eliminate negative sign
        n = abs(n), d = abs(d);
        
        // append integral part
        result += to_string(n / d);
        
        if (n % d == 0) {
            return result;
        }
        
        // fraction part starts
        result += '.';
        n = n % d;
        
        while (n != 0) {
            n *= 10;
            
            // if we meet this remainder before
            if (map.find(n) == map.end()) {
                map[n] = result.size();
            } else {
                result.insert(result.begin() + map.at(n), '(');
                result += ')';
                break;
            }

            result += to_string(n / d);
            n %= d;
        }
        return result;
    }
};
