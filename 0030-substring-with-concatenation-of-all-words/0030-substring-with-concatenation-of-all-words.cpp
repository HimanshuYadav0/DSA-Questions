
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) {
            return result;
        }

        int wordLength = words[0].length();
        int totalLength = wordLength * words.size();
        int strLength = s.length();

        unordered_map<string, int> wordCount;

        for (const string& word : words) {
            wordCount[word]++;
        }

        for (int i = 0; i < wordLength; ++i) {
            int left = i, right = i, count = 0;
            unordered_map<string, int> currentCount;

            while (right + wordLength <= strLength) {
                string word = s.substr(right, wordLength);
                right += wordLength;

                if (wordCount.find(word) != wordCount.end()) {
                    currentCount[word]++;
                    count++;

                    while (currentCount[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLength);
                        left += wordLength;
                        currentCount[leftWord]--;
                        count--;
                    }

                    if (count == words.size()) {
                        result.push_back(left);
                    }
                } else {
                    currentCount.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
