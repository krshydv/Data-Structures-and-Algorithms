class Solution {
    struct Node {
        long long cnt, wav;
    };

    string s;
    Node dp[20][11][11][20];
    bool vis[20][11][11][20];

    Node dfs(int pos, int p1, int p2, int len, bool tight) {
        if (pos == (int)s.size()) return {1, 0};

        if (!tight && vis[pos][p1 + 1][p2 + 1][len])
            return dp[pos][p1 + 1][p2 + 1][len];

        Node res = {0, 0};
        int lim = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= lim; d++) {
            bool nt = tight && (d == lim);

            if (len == 0 && d == 0) {
                Node nxt = dfs(pos + 1, -1, -1, 0, nt);
                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            } else if (len == 0) {
                Node nxt = dfs(pos + 1, d, -1, 1, nt);
                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            } else if (len == 1) {
                Node nxt = dfs(pos + 1, d, p1, 2, nt);
                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            } else {
                int add = ((p1 > p2 && p1 > d) || (p1 < p2 && p1 < d));
                Node nxt = dfs(pos + 1, d, p1, min(19, len + 1), nt);
                res.cnt += nxt.cnt;
                res.wav += nxt.wav + nxt.cnt * add;
            }
        }

        if (!tight) {
            vis[pos][p1 + 1][p2 + 1][len] = true;
            dp[pos][p1 + 1][p2 + 1][len] = res;
        }

        return res;
    }

    long long solve(long long x) {
        if (x < 0) return 0;
        s = to_string(x);
        memset(vis, 0, sizeof(vis));
        return dfs(0, -1, -1, 0, true).wav;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};