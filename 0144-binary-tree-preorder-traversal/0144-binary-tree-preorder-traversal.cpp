class Solution {
public:
    vector<int> ans;

    void dfs(TreeNode* r){
        if(!r) return;
        ans.push_back(r->val);
        dfs(r->left);
        dfs(r->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
