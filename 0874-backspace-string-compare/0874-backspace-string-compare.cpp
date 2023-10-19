class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return processString(s) == processString(t);
    }
    
    string processString(string str) {
        stack<char> result;
        
        for (char c : str) {
            if (c == '#') {
                if (!result.empty()) {
                    result.pop();
                }
            } else {
                result.push(c);
            }
        }
        
        string processedStr = "";
        while (!result.empty()) {
            processedStr += result.top();
            result.pop();
        }
        
        reverse(processedStr.begin(), processedStr.end());
        return processedStr;
    }
};
