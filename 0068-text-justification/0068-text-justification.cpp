class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0; 
        int n = words.size();
        
        while (i < n) {
            int lineStart = i;
            int lineLength = 0;
            
            while (i < n && lineLength + words[i].size() + i - lineStart <= maxWidth) {
                lineLength += words[i].size();
                i++;
            }
            
            int numWords = i - lineStart;
            int numSpaces = maxWidth - lineLength;
            int numGaps = numWords - 1;
            
            if (i == n || numGaps == 0) {
                string line = words[lineStart];
                for (int j = lineStart + 1; j < i; j++) {
                    line += ' ' + words[j];
                }
                line += string(maxWidth - line.length(), ' ');
                result.push_back(line);
            } else {
                int spacesBetweenWords = numSpaces / numGaps;
                int extraSpaces = numSpaces % numGaps;
                
                string line = words[lineStart];
                for (int j = lineStart + 1; j < i; j++) {
                    line += string(spacesBetweenWords, ' ');
                    if (extraSpaces > 0) {
                        line += ' ';
                        extraSpaces--;
                    }
                    line += words[j];
                }
                result.push_back(line);
            }
        }
        
        return result;
    }
};
