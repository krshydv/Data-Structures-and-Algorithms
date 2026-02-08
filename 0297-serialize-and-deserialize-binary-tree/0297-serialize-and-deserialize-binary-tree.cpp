class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            if(cur) {
                s += to_string(cur->val) + ",";
                q.push(cur->left);
                q.push(cur->right);
            } else s += "n,";
        }
        return s;
    }

    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;

        vector<string> v;
        string t;
        for(char c : data) {
            if(c == ',') {
                v.push_back(t);
                t.clear();
            } else t += c;
        }

        TreeNode* root = new TreeNode(stoi(v[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;

        while(!q.empty() && i < v.size()) {
            auto cur = q.front(); q.pop();

            if(v[i] != "n") {
                cur->left = new TreeNode(stoi(v[i]));
                q.push(cur->left);
            }
            i++;

            if(i < v.size() && v[i] != "n") {
                cur->right = new TreeNode(stoi(v[i]));
                q.push(cur->right);
            }
            i++;
        }

        return root;
    }
};
