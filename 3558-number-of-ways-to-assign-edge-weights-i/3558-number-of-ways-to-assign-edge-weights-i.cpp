class Solution {
public:
    static const int MOD = 1000000007;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        queue<pair<int, int>> q;
        vector<int> vis(n + 1, 0);

        q.push({1, 0});
        vis[1] = 1;

        int maxDepth = 0;

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            maxDepth = max(maxDepth, depth);

            for (int nei : adj[node]) {
                if (!vis[nei]) {
                    vis[nei] = 1;
                    q.push({nei, depth + 1});
                }
            }
        }

        if (maxDepth == 0) return 0;

        return power(2, maxDepth - 1);
    }
};