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
    void flatten(TreeNode* root) {
        if (!root) return;

        // Store the right subtree before modifying it.
        TreeNode* rightSubtree = root->right;

        // Recursively flatten the left subtree.
        flatten(root->left);

        // Attach the flattened left subtree to the right.
        root->right = root->left;
        root->left = nullptr;

        // Find the end of the flattened left subtree and attach the right subtree.
        TreeNode* current = root;
        while (current->right) {
            current = current->right;
        }
        current->right = rightSubtree;

        // Continue flattening the right subtree.
        flatten(rightSubtree);
    }
};
