class Solution {
public:
    bool f(TreeNode* a, TreeNode* b){
        if(!a&&!b) return true;
        if(!a||!b||a->val!=b->val) return false;
        return f(a->left,b->right)&&f(a->right,b->left);
    }

    bool isSymmetric(TreeNode* root) {
        return !root||f(root->left,root->right);
    }
};
