class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) {
            return {0};
        }

        vector<int> result = backtrack(n, 0);

        return result;
    }

private:
    vector<int> backtrack(int n, int curr) {
        if (n == 0) {
            return {curr};
        }

        vector<int> seq = backtrack(n - 1, curr);
        int add_value = 1 << (n - 1);
        vector<int> reflected_seq;
        
        for (int i = seq.size() - 1; i >= 0; i--) {
            reflected_seq.push_back(seq[i] + add_value);
        }
        
        seq.insert(seq.end(), reflected_seq.begin(), reflected_seq.end());

        return seq;
    }
};