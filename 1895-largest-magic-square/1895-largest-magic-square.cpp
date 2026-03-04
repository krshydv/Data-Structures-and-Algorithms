class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        for(int k = min(m,n); k >= 1; k--){
            for(int i = 0; i + k <= m; i++){
                for(int j = 0; j + k <= n; j++){
                    
                    int diag1 = 0, diag2 = 0;
                    
                    for(int x = 0; x < k; x++){
                        diag1 += grid[i+x][j+x];
                        diag2 += grid[i+x][j+k-1-x];
                    }
                    
                    if(diag1 != diag2) continue;
                    
                    bool ok = true;
                    
                    for(int r = 0; r < k; r++){
                        int sum = 0;
                        for(int c = 0; c < k; c++)
                            sum += grid[i+r][j+c];
                        if(sum != diag1) ok = false;
                    }
                    
                    for(int c = 0; c < k; c++){
                        int sum = 0;
                        for(int r = 0; r < k; r++)
                            sum += grid[i+r][j+c];
                        if(sum != diag1) ok = false;
                    }
                    
                    if(ok) return k;
                }
            }
        }
        
        return 1;
    }
};