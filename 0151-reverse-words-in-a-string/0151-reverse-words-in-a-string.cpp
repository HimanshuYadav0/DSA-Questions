class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                continue;  // Skip spaces.
            }
            string word = "";
            
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }
            words.push_back(word);
        }
        
        reverse(words.begin(), words.end());
        
        string result = "";
        for (const string& word : words) {
            result += word + " ";
        }
        
        if (!result.empty()) {
            result.pop_back();
        }
        
        return result;
    }
};
