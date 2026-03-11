class Solution {
public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> rootMap;
        unordered_map<int, int> count;

        for (auto t : trees) {
            rootMap[t->val] = t;
            count[t->val]++;
            if (t->left) count[t->left->val]++;
            if (t->right) count[t->right->val]++;
        }

        TreeNode* root = nullptr;
        for (auto t : trees) {
            if (count[t->val] == 1) {
                root = t;
                break;
            }
        }

        if (!root) return nullptr;

        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();

            if (node->left) {
                if (rootMap.count(node->left->val) && rootMap[node->left->val] != node) {
                    node->left = rootMap[node->left->val];
                    rootMap.erase(node->left->val);
                }
                stk.push(node->left);
            }

            if (node->right) {
                if (rootMap.count(node->right->val) && rootMap[node->right->val] != node) {
                    node->right = rootMap[node->right->val];
                    rootMap.erase(node->right->val);
                }
                stk.push(node->right);
            }
        }

        if (rootMap.size() != 1) return nullptr;

        TreeNode* prev = nullptr;
        if (!isValidBST(root, prev)) return nullptr;

        return root;
    }

    bool isValidBST(TreeNode* node, TreeNode*& prev) {
        if (!node) return true;
        if (!isValidBST(node->left, prev)) return false;
        if (prev && prev->val >= node->val) return false;
        prev = node;
        return isValidBST(node->right, prev);
    }
};