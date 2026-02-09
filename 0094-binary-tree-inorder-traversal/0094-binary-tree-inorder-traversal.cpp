class Solution {
public:
    vector<int> v;

    void dfs(TreeNode* r){
        if(!r) return;
        dfs(r->left);
        v.push_back(r->val);
        dfs(r->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return v;
    }
};
