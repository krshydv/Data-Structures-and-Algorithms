class Solution {
public:
    int prev = -1;
    int ans = INT_MAX;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev != -1) {
            ans = min(ans, root->val - prev);
        }
        prev = root->val;

        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }
};