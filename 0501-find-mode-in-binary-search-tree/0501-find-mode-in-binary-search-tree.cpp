/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        TreeNode* prev = nullptr;
        int currentCount = 1;
        int maxCount = 0;

        findModeHelper(root, prev, currentCount, maxCount, result);

        return result;
    }

    void findModeHelper(TreeNode* node, TreeNode*& prev, int& currentCount, int& maxCount, vector<int>& result) {
        if (!node) return;

        findModeHelper(node->left, prev, currentCount, maxCount, result);

        // Update currentCount
        if (prev) {
            if (node->val == prev->val) {
                currentCount++;
            } else {
                currentCount = 1;
            }
        }

        // Update maxCount and result
        if (currentCount > maxCount) {
            maxCount = currentCount;
            result = {node->val};
        } else if (currentCount == maxCount) {
            result.push_back(node->val);
        }

        prev = node;

        findModeHelper(node->right, prev, currentCount, maxCount, result);
    }
};

