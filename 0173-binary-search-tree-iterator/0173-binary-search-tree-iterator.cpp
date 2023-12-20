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


class BSTIterator {
private:
    std::stack<TreeNode*> st;

public:
    BSTIterator(TreeNode* root) {
        // Initialize the stack with the leftmost path from the root
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }
    }

    int next() {
        // Pop the top node from the stack (current smallest)
        TreeNode* node = st.top();
        st.pop();

        // Explore the right subtree of the popped node
        TreeNode* right = node->right;
        while (right != nullptr) {
            st.push(right);
            right = right->left;
        }

        // Return the value of the popped node
        return node->val;
    }

    bool hasNext() {
        // If the stack is not empty, there are more nodes to traverse
        return !st.empty();
    }
};


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */