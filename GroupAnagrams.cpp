class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Iterate every string and group them by a map
        // key is sorted string and value is a vector
        unordered_map<string, vector<string>> map;
        for (auto str: strs) {
            string copy = str;
            sort(copy.begin(), copy.end());
            if (map.find(copy) == map.end()) {
                vector<string> v;
                v.push_back(str);
                map[copy] = v;
            } else {
                map[copy].push_back(str);
            }
        }
        
        // Group all vectors in a vector
        vector<vector<string>> res;
        for (auto i: map) {
            res.push_back(i.second);
        }
        return res;
    }
};