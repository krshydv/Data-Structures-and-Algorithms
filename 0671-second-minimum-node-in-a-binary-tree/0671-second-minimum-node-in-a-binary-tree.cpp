class Solution {
public:
    long firstMin;
    long secondMin = LONG_MAX;
    
    void dfs(TreeNode* root) {
        if (!root) return;
        
        if (root->val > firstMin && root->val < secondMin)
            secondMin = root->val;
        
        dfs(root->left);
        dfs(root->right);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        firstMin = root->val;
        dfs(root);
        return secondMin == LONG_MAX ? -1 : secondMin;
    }
};