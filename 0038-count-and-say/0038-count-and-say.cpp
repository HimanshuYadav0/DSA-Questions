class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1"; 
        }
        
        string prevTerm = countAndSay(n - 1);
        string result;
        
        int count = 1;
        char say = prevTerm[0];
        
        for (int i = 1; i < prevTerm.length(); i++) {
            if (prevTerm[i] == say) {
                count++;
            } else {
                result += to_string(count) + say;
                count = 1;
                say = prevTerm[i];
            }
        }
        
        result += to_string(count) + say; 
        
        return result;
    }
};
