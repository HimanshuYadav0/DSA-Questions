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
    int maxAncestorDiff(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        return dfs(root, root->val, root->val);
    }
    
    int dfs(TreeNode* node, int min_val, int max_val) {
        if (!node) {
            return max_val - min_val;
        }
        
        // Update min and max values encountered so far
        min_val = std::min(min_val, node->val);
        max_val = std::max(max_val, node->val);
        
        // Recursively calculate the maximum difference in the left and right subtrees
        int left_diff = dfs(node->left, min_val, max_val);
        int right_diff = dfs(node->right, min_val, max_val);
        
        // Return the maximum difference among the current node, left subtree, and right subtree
        return std::max({left_diff, right_diff, max_val - min_val});
    }
};


