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
    int averageOfSubtree(TreeNode* root);
private:
    typedef pair<int, int> SumCount;
    SumCount traverse(TreeNode* node, int& ans);
};

int Solution::averageOfSubtree(TreeNode* root) {
    int ans = 0;
    traverse(root, ans);
    return ans;
}

Solution::SumCount Solution::traverse(TreeNode* node, int& ans) {
    if (node == nullptr) return {0, 0};
    SumCount left = traverse(node->left, ans);
    SumCount right = traverse(node->right, ans);
    int sum = node->val + left.first + right.first;
    int count = 1 + left.second + right.second;
    int avg = sum / count;
    if (avg == node->val) ans++;
    return {sum, count};
}