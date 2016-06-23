class Solution {
public:
    string simplifyPath(string path) {
        stack<string> paths;
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                continue;
            }
            // find a string between /
            int pos = path.find('/', i+1);
            string name;
            if (pos == string::npos) {
                name = path.substr(i);
            } else {
                name = path.substr(i, pos-i);
            }
            
            if (name == "..") {
                if (!paths.empty()) {
                    paths.pop();
                }
            } else if (name != ".") {
                paths.push(name);
            }
            
            if (pos == string::npos) {
                break;
            }
            
            i = pos;
        }
        
        // print the path from the stack
        string res;
        while (!paths.empty()) {
            res = "/" + paths.top() + res;
            paths.pop();
        }
        
        if (res == "")  return "/";
        return res;
    }
};