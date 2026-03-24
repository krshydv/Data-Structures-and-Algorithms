class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int mod = 12345;

        vector<int> arr;
        for (auto &row : grid)
            for (int x : row)
                arr.push_back(x % mod);

        int size = arr.size();
        vector<int> pref(size, 1), suff(size, 1);

        for (int i = 1; i < size; i++)
            pref[i] = (pref[i-1] * arr[i-1]) % mod;

        for (int i = size-2; i >= 0; i--)
            suff[i] = (suff[i+1] * arr[i+1]) % mod;

        vector<vector<int>> res(m, vector<int>(n));
        int k = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = (pref[k] * suff[k]) % mod;
                k++;
            }
        }

        return res;
    }
};