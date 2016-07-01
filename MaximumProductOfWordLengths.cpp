// looked forum
class Solution {
public:
    // use an integer to represent the letters a word has
    int maxProduct(vector<string>& words) {
        if (words.size() < 2) return 0;
        sort(words.begin(), words.end(), compare);
        
        // build the letters distribution of words
        vector<int> distribution (words.size());
        for (int i = 0; i < words.size(); i++) {
            for (char c: words[i]) {
                distribution[i] |= 1 << (c - 'a');
            }
        }
        
        // choose each two words and compare
        int max = 0;
        for (int i = 0; i < words.size(); i++) {
            // pruning
            if (words[i].size() * words[i].size() <= max) {
                break;
            }
            
            for (int j = i+1; j < words.size(); j++) {
                // pruning 
                if (words[i].size() * words[j].size() <= max) {
                    break;
                }
                // do share common letters
                if (distribution[i] & distribution[j]) {
                    continue;
                }
                max = words[i].size() * words[j].size();
            }
        }
        return max;
    }
    
    static bool compare(string a, string b) {
        return a.size() > b.size();
    }
};