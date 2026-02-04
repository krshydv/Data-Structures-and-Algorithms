class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) fresh++;
            }
        }

        int minutes = 0;
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};

        while(!q.empty() && fresh > 0) {
            int sz = q.size();
            while(sz--) {
                auto [x,y] = q.front();
                q.pop();
                for(int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx,ny});
                    }
                }
            }
            minutes++;
        }

        if(fresh > 0) return -1;
        return minutes;
    }
};
