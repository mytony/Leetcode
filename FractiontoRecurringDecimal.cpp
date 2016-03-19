class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result;
        unordered_map<int, int> map;
        bool firstTime = true; // first time n < d, have to put dot
        bool neg = false;
        long n = numerator, d = denominator; // prevent error caused by INT_MIN
        
        if (!n) {
            return "0";
        }
        // check sign
        if (n < 0) {
            n = abs(n);
            neg = !neg;
        }
        if (d < 0) {
            d = abs(d);
            neg = !neg;
        }
        // concise way to check sign
        // if (n < 0 ^ d < 0)

        while (n != 0) {
            if (n < d) {
                if (firstTime) {
                    if (result.empty()) {
                        result += "0";
                    }
                    result += ".";
                    firstTime = false;
                } else {
                    if (map.find(n) == map.end()) {
                        map[n] = result.size();
                    } else {
                        result.insert(result.begin() + map.at(n), '(');
                        result += ')';
                        return result;
                    }
                    result += "0";
                }
                n *= 10;
            } else {
                if (map.find(n) == map.end()) {
                    map[n] = result.size();
                } else {
                    result.insert(result.begin() + map.at(n), '(');
                    result += ')';
                    break;
                }
                result += to_string(n / d);
                n %= d;
                if (n != 0) {
                    n *= 10;
                    if (firstTime) {
                        result += ".";
                        firstTime = false;
                    }
                }
            }
        }
        return neg ? "-" + result : result;
    }
};
