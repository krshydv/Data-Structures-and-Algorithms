class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        const long long INF = 1e18;

        unordered_map<string, int> id;
        int idx = 0;

        for (auto &s : original) if (!id.count(s)) id[s] = idx++;
        for (auto &s : changed) if (!id.count(s)) id[s] = idx++;

        vector<vector<long long>> dist(idx, vector<long long>(idx, INF));
        for (int i = 0; i < idx; i++) dist[i][i] = 0;

        for (int i = 0; i < original.size(); i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < idx; k++)
            for (int i = 0; i < idx; i++)
                for (int j = 0; j < idx; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        unordered_map<int, vector<string>> byLen;
        for (auto &s : id) {
            byLen[s.first.size()].push_back(s.first);
        }

        int n = source.size();
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;

            if (source[i] == target[i])
                dp[i + 1] = min(dp[i + 1], dp[i]);

            for (auto &p : byLen) {
                int len = p.first;
                if (i + len > n) continue;

                string s = source.substr(i, len);
                string t = target.substr(i, len);

                if (id.count(s) && id.count(t)) {
                    long long d = dist[id[s]][id[t]];
                    if (d < INF)
                        dp[i + len] = min(dp[i + len], dp[i] + d);
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};