

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            if (isValid(current)) {
                result.push_back(current);
                found = true;
            }

            if (found) {
                // If a valid string is found, we don't need to explore further
                continue;
            }

            // Explore all possible strings after removing each character
            for (int i = 0; i < current.length(); i++) {
                if (current[i] == '(' || current[i] == ')') {
                    string next = current.substr(0, i) + current.substr(i + 1);

                    if (visited.find(next) == visited.end()) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
        }

        return result;
    }

private:
    bool isValid(const string& s) {
        int count = 0;

        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                if (count == 0) {
                    return false; // More closing parentheses than opening ones
                }
                count--;
            }
        }

        return count == 0; // Valid if count is zero
    }
};
