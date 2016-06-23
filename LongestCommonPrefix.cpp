class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)   return "";
        if (strs.size() == 1)   return strs[0];
        string lcp = strs[0];
        
        // For every string, compare with LCP and update LCP
        for (int i = 1; i < strs.size(); i++) {
            int minLen = min(strs[i].size(), lcp.size());
            string tmpSol;
            for (int j = 0; j < minLen; j++) {
                if (strs[i][j] != lcp[j]) {
                    tmpSol = lcp.substr(0, j);
                    break;
                }
                if (j == minLen - 1) {
                    tmpSol = lcp.substr(0, j+1);
                    break;
                }
            }
            lcp = tmpSol;
            if (lcp == "")  return "";
        }
        return lcp;
    }
};