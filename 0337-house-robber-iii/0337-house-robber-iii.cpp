class Solution {
public:
    int rob(TreeNode* root) {
        pair<int,int> res = dfs(root);
        return max(res.first, res.second);
    }

private:
    pair<int,int> dfs(TreeNode* node) {
        if (!node) return {0, 0};

        pair<int,int> left = dfs(node->left);
        pair<int,int> right = dfs(node->right);

        int robNode = node->val + left.second + right.second;
        int skipNode = max(left.first, left.second) + 
                       max(right.first, right.second);

        return {robNode, skipNode};
    }
};