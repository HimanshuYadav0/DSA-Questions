class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> arr(n);

        arr[0] = pref[0];  // Initialize the first element of 'arr'.

        for (int i = 1; i < n; i++) {
            arr[i] = pref[i] ^ pref[i - 1];  // Calculate the next element of 'arr'.
        }

        return arr;
    }
};

