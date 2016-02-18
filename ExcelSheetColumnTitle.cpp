// 這題特別不會
class Solution {
public:
    string convertToTitle(int n) {
        string s, result;
        do{
            int r = n % 26;
            n /= 26;
            if(r == 0){
                r = 26;
                n--;
            }
            s += 'A' - 1 + r;
        } while(n > 0);
        for(int i=s.size()-1; i>=0; i--){
            result += s[i];
        }
        return result;
    }
};
