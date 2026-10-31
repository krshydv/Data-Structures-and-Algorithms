class Solution {
public:
    static const int MOD = 1000000007;

    int m, n;
    vector<vector<int>> grid;
    vector<vector<vector<int>>> dp;

    int dfs(int r, int c, int dir) {
        if (r < 0 || r >= m || c < 0 || c >= n)
            return 0;

        if (r == m - 1 && c == n - 1)
            return 1;

        int &res = dp[r][c][dir];
        if (res != -1)
            return res;

        if (grid[r][c] == 1) {
            if (dir == 0)
                return res = dfs(r + 1, c, 1);
            else
                return res = dfs(r, c + 1, 0);
        }

        long long ans = 0;

        ans += dfs(r, c + 1, 0);
        ans += dfs(r + 1, c, 1);

        return res = ans % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(2, -1)));

        long long ans = 0;

        ans += dfs(0, 1, 0);
        ans += dfs(1, 0, 1);

        return ans % MOD;
    }
};