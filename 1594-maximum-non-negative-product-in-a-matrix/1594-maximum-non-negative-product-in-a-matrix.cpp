class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const long mod = 1e9 + 7;

        vector<vector<long>> mx(m, vector<long>(n)), mn(m, vector<long>(n));
        mx[0][0] = mn[0][0] = grid[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                long a = LONG_MIN, b = LONG_MAX;

                if (i > 0) {
                    a = max(a, max(mx[i-1][j] * grid[i][j], mn[i-1][j] * grid[i][j]));
                    b = min(b, min(mx[i-1][j] * grid[i][j], mn[i-1][j] * grid[i][j]));
                }

                if (j > 0) {
                    a = max(a, max(mx[i][j-1] * grid[i][j], mn[i][j-1] * grid[i][j]));
                    b = min(b, min(mx[i][j-1] * grid[i][j], mn[i][j-1] * grid[i][j]));
                }

                mx[i][j] = a;
                mn[i][j] = b;
            }
        }

        return mx[m-1][n-1] < 0 ? -1 : mx[m-1][n-1] % mod;
    }
};