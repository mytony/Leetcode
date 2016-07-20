class Solution {
public:
    string getHint(string secret, string guess) {
        int size = secret.size();
        int a = 0, b = 0;
        // This data structure can be changed to array since only digits
        unordered_map<char, pair<int, int>> map;
        
        // compare two characters at same position of two strings
        // count it if they are same
        // otherwise count how many times it appears in hash table
        for (int i = 0; i < size; i++) {
            char s = secret[i];
            char g = guess[i];
            
            if (s == g) {
                a++;
            } else {
                map[s].first++;
                map[g].second++;
            }
        }
        
        // calculate how many Cows
        for (auto kv: map) {
            int n1 = kv.second.first;
            int n2 = kv.second.second;
            b += min(n1, n2);
        }
        
        // print the string
        string res = to_string(a) + "A" + to_string(b) + "B";
        return res;
    }
};