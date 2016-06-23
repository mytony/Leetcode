class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1, n2; // number of each level
        int p1 = 0, p2 = 0; // dot position
        int s1 = 0, s2 = 0; // start point of number
        bool flag1 = false, flag2 = false;

        while (p1 != string::npos || p2 != string::npos) {
            p1 = version1.find('.', s1);
            p2 = version2.find('.', s2);
            
            if (p1 == string::npos) {
                if (flag1) { // not the first time
                    n1 = 0;
                } else { // first time encounter the end
                    n1 = stoi(version1.substr(s1));
                    flag1 = true;
                }
            } else {
                n1 = stoi(version1.substr(s1, p1-s1));
                s1 = p1 + 1;
            }
            
            if (p2 == string::npos) {
                if (flag2) {
                    n2 = 0;
                } else {
                    n2 = stoi(version2.substr(s2));
                    flag2 = true;
                }
            } else {
                n2 = stoi(version2.substr(s2, p2-s2));
                s2 = p2 + 1;
            }
            
            if (n1 > n2)    return 1;
            else if (n1 < n2)   return -1;
        }
        return 0;
    }
};