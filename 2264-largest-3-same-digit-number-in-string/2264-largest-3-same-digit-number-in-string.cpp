

class Solution {
public:
    string largestGoodInteger(string num) {
        string maxGoodInteger = "";  // Variable to store the maximum good integer found
        
        for (int i = 0; i <= num.length() - 3; ++i) {
            string substring = num.substr(i, 3);
            
            if (isGoodInteger(substring) && substring > maxGoodInteger) {
                maxGoodInteger = substring;
            }
        }
        
        return maxGoodInteger;
    }

private:
    bool isGoodInteger(const string& s) {
        return s[0] == s[1] && s[1] == s[2];
    }
};
