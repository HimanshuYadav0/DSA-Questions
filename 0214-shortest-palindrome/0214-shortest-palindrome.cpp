
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        
        string concat = s + "#" + rev;

        vector<int> kmpTable(concat.size(), 0);
        for (int i = 1, len = 0; i < concat.size(); ) {
            if (concat[i] == concat[len]) {
                kmpTable[i++] = ++len;
            } else {
                if (len) {
                    len = kmpTable[len - 1];
                } else {
                    kmpTable[i++] = 0;
                }
            }
        }

        int len = kmpTable.back();

        return rev.substr(0, rev.size() - len) + s;
    }
};
