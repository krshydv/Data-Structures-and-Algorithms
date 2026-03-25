class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long total = 0;
        
        for (auto &row : grid)
            for (int x : row)
                total += x;
        
        long long sum = 0;
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++)
                sum += grid[i][j];
            if (sum * 2 == total) return true;
        }
        
        sum = 0;
        
        for (int j = 0; j < m - 1; j++) {
            for (int i = 0; i < n; i++)
                sum += grid[i][j];
            if (sum * 2 == total) return true;
        }
        
        return false;
    }
};