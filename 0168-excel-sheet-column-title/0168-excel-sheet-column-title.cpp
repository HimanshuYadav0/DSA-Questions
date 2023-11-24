
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            int remainder = (columnNumber - 1) % 26; // Adjusting to 0-25 range
            char digit = 'A' + remainder; // Convert remainder to corresponding character
            
            result = digit + result; // Prepend the character to the result
            
            columnNumber = (columnNumber - 1) / 26; // Update columnNumber for the next iteration
        }
        
        return result;
    }
};
