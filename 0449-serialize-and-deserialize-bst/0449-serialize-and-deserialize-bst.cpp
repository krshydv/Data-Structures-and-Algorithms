class Codec {
public:
    void dfs(TreeNode* node, string& s) {
        if(!node) return;
        s += to_string(node->val) + ",";
        dfs(node->left, s);
        dfs(node->right, s);
    }

    TreeNode* buildTree(vector<int>& v, int& idx, int low, int high) {
        if(idx >= v.size() || v[idx] < low || v[idx] > high) return nullptr;

        TreeNode* root = new TreeNode(v[idx++]);
        root->left = buildTree(v, idx, low, root->val);
        root->right = buildTree(v, idx, root->val, high);
        return root;
    }

    string serialize(TreeNode* root) {
        string res;
        dfs(root, res);
        return res;
    }

    TreeNode* deserialize(string data) {
        vector<int> vals;
        string cur;

        for(char c : data) {
            if(c == ',') {
                vals.push_back(stoi(cur));
                cur.clear();
            } else cur += c;
        }

        int idx = 0;
        return buildTree(vals, idx, INT_MIN, INT_MAX);
    }
};
