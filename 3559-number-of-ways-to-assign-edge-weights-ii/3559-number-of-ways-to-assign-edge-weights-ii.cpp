class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        vector<vector<int>> g(n + 1);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n + 1));
        vector<int> depth(n + 1);

        function<void(int,int)> dfs = [&](int u, int p) {
            up[0][u] = p;
            for (int v : g[u]) {
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
        };

        dfs(1, 0);

        for (int j = 1; j < LOG; j++) {
            for (int i = 1; i <= n; i++) {
                up[j][i] = up[j - 1][i] ? up[j - 1][up[j - 1][i]] : 0;
            }
        }

        auto lca = [&](int a, int b) {
            if (depth[a] < depth[b]) swap(a, b);

            int diff = depth[a] - depth[b];
            for (int j = 0; j < LOG; j++) {
                if (diff & (1 << j)) a = up[j][a];
            }

            if (a == b) return a;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][a] != up[j][b]) {
                    a = up[j][a];
                    b = up[j][b];
                }
            }

            return up[0][a];
        };

        vector<int> pow2(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2LL) % MOD;
        }

        vector<int> ans;

        for (auto& q : queries) {
            int u = q[0], v = q[1];

            int w = lca(u, v);
            int d = depth[u] + depth[v] - 2 * depth[w];

            if (d == 0) ans.push_back(0);
            else ans.push_back(pow2[d - 1]);
        }

        return ans;
    }
};