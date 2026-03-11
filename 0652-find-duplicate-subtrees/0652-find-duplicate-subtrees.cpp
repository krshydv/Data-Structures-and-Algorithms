class Solution {
public:
    unordered_map<string, int> seen;
    vector<TreeNode*> result;

    string serialize(TreeNode* node) {
        if (!node) return "#";

        string s = to_string(node->val) + "," + serialize(node->left) + "," + serialize(node->right);

        if (seen[s] == 1)
            result.push_back(node);

        seen[s]++;
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return result;
    }
};