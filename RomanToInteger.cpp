class Solution {
public:
    int romanToInt(string s) {
        int i = 0;
        int sum = 0;
        unordered_map<char, int> map = {
            {'I', 1}, 
            {'V', 5}, 
            {'X', 10}, 
            {'L', 50}, 
            {'C', 100}, 
            {'D', 500},
            {'M', 1000}, 
        };
        while(i < s.length()){
            if(map[s[i]] < map[s[i+1]]){
                sum += map[s[i+1]] - map[s[i]];
                i += 2;
            } else {
                sum += map[s[i]];
                i++;
            }
        }
        return sum;
    }
};
