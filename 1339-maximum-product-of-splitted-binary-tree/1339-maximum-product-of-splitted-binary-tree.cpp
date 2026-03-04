class Solution {
public:
    long long total = 0;
    long long ans = 0;
    const int MOD = 1e9 + 7;

    long long sumTree(TreeNode* root){
        if(!root) return 0;
        return root->val + sumTree(root->left) + sumTree(root->right);
    }

    long long dfs(TreeNode* root){
        if(!root) return 0;

        long long cur = root->val + dfs(root->left) + dfs(root->right);

        ans = max(ans, cur * (total - cur));

        return cur;
    }

    int maxProduct(TreeNode* root) {
        total = sumTree(root);
        dfs(root);
        return ans % MOD;
    }
};