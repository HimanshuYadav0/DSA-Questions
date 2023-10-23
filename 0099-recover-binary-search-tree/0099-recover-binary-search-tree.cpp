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
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;  
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;   
        
        recoverTreeHelper(root, first, second, prev);

        
        if (first && second) {
            swap(first->val, second->val);
        }
    }

    void recoverTreeHelper(TreeNode* node, TreeNode*& first, TreeNode*& second, TreeNode*& prev) {
        if (!node) {
            return;
        }

       
        recoverTreeHelper(node->left, first, second, prev);

        if (prev && node->val < prev->val) {
            if (!first) {
                first = prev;
            }
            second = node;
        }

        prev = node;

        recoverTreeHelper(node->right, first, second, prev);
    }
};
