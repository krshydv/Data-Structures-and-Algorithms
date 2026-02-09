class Solution {
public:
    int maxDepth(TreeNode* r) {
        if(!r) return 0;
        return 1+max(maxDepth(r->left),maxDepth(r->right));
    }
};
