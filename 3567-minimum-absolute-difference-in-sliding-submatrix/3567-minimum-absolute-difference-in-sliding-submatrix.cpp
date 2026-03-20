class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int R = m - k + 1, C = n - k + 1;
        vector<vector<int>> ans(R, vector<int>(C, 0));

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                vector<int> vals;
                vals.reserve(k * k);

                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        vals.push_back(grid[x][y]);
                    }
                }

                sort(vals.begin(), vals.end());

                int best = INT_MAX;
                for (int t = 1; t < (int)vals.size(); t++) {
                    if (vals[t] != vals[t - 1]) {
                        best = min(best, vals[t] - vals[t - 1]);
                    }
                }

                ans[i][j] = (best == INT_MAX ? 0 : best);
            }
        }

        return ans;
    }
};