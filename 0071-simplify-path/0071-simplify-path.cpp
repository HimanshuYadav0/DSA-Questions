class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string directory = "";
        
        path += '/';
        
        for (char c : path) {
            if (c == '/') {
                if (directory == "..") {
                    if (!s.empty()) {
                        s.pop();
                    }
                } else if (directory != "." && !directory.empty()) {
                    s.push(directory);
                }
                directory = "";
            } else {
                directory += c;
            }
        }
        
        string result = "";
        while (!s.empty()) {
            result = '/' + s.top() + result;
            s.pop();
        }
        
        return result.empty() ? "/" : result;
    }
};
