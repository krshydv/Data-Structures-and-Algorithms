class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        int len = m + n - 1;

        if (len % 2 == 1)
            return false;

        vector<vector<vector<bool>>> dp(
            m,
            vector<vector<bool>>(n, vector<bool>(len + 1, false))
        );

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int balance = 0; balance <= len; balance++) {
                    if (!dp[i][j][balance])
                        continue;

                    if (i + 1 < m) {
                        int next = balance + (grid[i + 1][j] == '(' ? 1 : -1);
                        if (next >= 0)
                            dp[i + 1][j][next] = true;
                    }

                    if (j + 1 < n) {
                        int next = balance + (grid[i][j + 1] == '(' ? 1 : -1);
                        if (next >= 0)
                            dp[i][j + 1][next] = true;
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};