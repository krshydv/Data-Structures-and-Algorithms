class Solution {
public:
    vector<int> v;

    void dfs(TreeNode* r){
        if(!r) return;
        dfs(r->left);
        dfs(r->right);
        v.push_back(r->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return v;
    }
};
