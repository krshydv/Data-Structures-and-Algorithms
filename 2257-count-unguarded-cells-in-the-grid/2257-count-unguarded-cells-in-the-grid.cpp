class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        for(auto &g : guards)
            grid[g[0]][g[1]] = 1;
        
        for(auto &w : walls)
            grid[w[0]][w[1]] = 2;
        
        vector<vector<bool>> seen(m, vector<bool>(n,false));
        
        for(auto &g : guards){
            
            int r = g[0], c = g[1];
            
            for(int i=r-1;i>=0;i--){
                if(grid[i][c]==1 || grid[i][c]==2) break;
                seen[i][c] = true;
            }
            
            for(int i=r+1;i<m;i++){
                if(grid[i][c]==1 || grid[i][c]==2) break;
                seen[i][c] = true;
            }
            
            for(int j=c-1;j>=0;j--){
                if(grid[r][j]==1 || grid[r][j]==2) break;
                seen[r][j] = true;
            }
            
            for(int j=c+1;j<n;j++){
                if(grid[r][j]==1 || grid[r][j]==2) break;
                seen[r][j] = true;
            }
        }
        
        int ans = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && !seen[i][j])
                    ans++;
            }
        }
        
        return ans;
    }
};