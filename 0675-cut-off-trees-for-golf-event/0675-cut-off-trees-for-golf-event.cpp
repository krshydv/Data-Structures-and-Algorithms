class Solution {
public:

    int bfs(vector<vector<int>>& forest, int sr, int sc, int tr, int tc) {
        if(sr == tr && sc == tc) return 0;

        int m = forest.size();
        int n = forest[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n,0));

        q.push({sr,sc});
        vis[sr][sc] = 1;

        int steps = 0;

        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()) {
            int size = q.size();
            steps++;

            while(size--) {
                auto [r,c] = q.front();
                q.pop();

                for(auto &d : dir) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr>=0 && nc>=0 && nr<m && nc<n &&
                       !vis[nr][nc] && forest[nr][nc]!=0) {

                        if(nr==tr && nc==tc)
                            return steps;

                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
        }

        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {

        int m = forest.size();
        int n = forest[0].size();

        vector<tuple<int,int,int>> trees;

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(forest[i][j] > 1)
                    trees.push_back({forest[i][j],i,j});

        sort(trees.begin(),trees.end());

        int sr=0, sc=0;
        int ans=0;

        for(auto &[h,r,c] : trees) {

            int dist = bfs(forest,sr,sc,r,c);

            if(dist==-1) return -1;

            ans += dist;
            sr = r;
            sc = c;
        }

        return ans;
    }
};