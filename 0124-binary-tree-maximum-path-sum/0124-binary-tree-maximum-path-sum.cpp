class Solution {
public:
    int ans = INT_MIN;

    int dfs(TreeNode* root) {
        if(!root) return 0;

        int l = max(0, dfs(root->left));
        int r = max(0, dfs(root->right));

        ans = max(ans, root->val + l + r);

        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
