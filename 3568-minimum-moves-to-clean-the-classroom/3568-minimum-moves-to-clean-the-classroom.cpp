class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sx = 0, sy = 0;
        int cnt = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                } else if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        if (cnt == 0) return 0;

        int masks = 1 << cnt;
        int fullMask = masks - 1;

        vector<vector<vector<vector<bool>>>> vis(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(masks, false)
                )
            )
        );

        queue<tuple<int, int, int, int>> q;

        q.push({sx, sy, energy, fullMask});
        vis[sx][sy][energy][fullMask] = true;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [x, y, e, mask] = q.front();
                q.pop();

                if (mask == 0) return moves;

                if (e == 0) continue;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;

                    if (classroom[nx][ny] == 'X')
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    if (classroom[nx][ny] == 'R')
                        ne = energy;

                    if (classroom[nx][ny] == 'L')
                        nmask &= ~(1 << id[nx][ny]);

                    if (!vis[nx][ny][ne][nmask]) {
                        vis[nx][ny][ne][nmask] = true;
                        q.push({nx, ny, ne, nmask});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};