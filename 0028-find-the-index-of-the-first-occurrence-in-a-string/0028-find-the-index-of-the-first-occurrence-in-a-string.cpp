class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();

        if (n == 0) {
            return 0;
        }

       
        vector<int> fail(n, 0);
        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && needle[i] != needle[j]) {
                j = fail[j - 1];
            }
            if (needle[i] == needle[j]) {
                j++;
            }
            fail[i] = j;
        }

        for (int i = 0, j = 0; i < m; i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = fail[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == n) {
                return i - n + 1; 
            }
        }

        return -1; 
    }
};
