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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafValues1, leafValues2;
        getLeafValues(root1, leafValues1);
        getLeafValues(root2, leafValues2);

        return leafValues1 == leafValues2;
    }

private:
    void getLeafValues(TreeNode* root, vector<int>& leafValues) {
        if (!root) {
            return;
        }

        stack<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            TreeNode* current = nodes.top();
            nodes.pop();

            if (!current->left && !current->right) {
                leafValues.push_back(current->val);
            }

            if (current->right) {
                nodes.push(current->right);
            }

            if (current->left) {
                nodes.push(current->left);
            }
        }
    }
};