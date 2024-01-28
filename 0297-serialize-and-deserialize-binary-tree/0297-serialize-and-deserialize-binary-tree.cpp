/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "null";
        }

        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        vector<string> nodes;
        string token;

        while (getline(ss, token, ',')) {
            nodes.push_back(token);
        }

        int index = 0;
        return deserializeHelper(nodes, index);
    }

private:
    TreeNode* deserializeHelper(const vector<string>& nodes, int& index) {
        if (index >= nodes.size() || nodes[index] == "null") {
            index++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[index++]));
        root->left = deserializeHelper(nodes, index);
        root->right = deserializeHelper(nodes, index);

        return root;
    }
};

