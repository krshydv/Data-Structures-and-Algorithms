class Solution {
public:
    bool ok(vector<vector<char>>& b, int r, int c, char v) {
        for (int i = 0; i < 9; i++) {
            if (b[r][i] == v) return false;
            if (b[i][c] == v) return false;
        }
        int sr = (r / 3) * 3;
        int sc = (c / 3) * 3;
        for (int i = sr; i < sr + 3; i++) {
            for (int j = sc; j < sc + 3; j++) {
                if (b[i][j] == v) return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<char>>& b, int r, int c) {
        if (r == 9) return true;
        if (c == 9) return dfs(b, r + 1, 0);
        if (b[r][c] != '.') return dfs(b, r, c + 1);

        for (char x = '1'; x <= '9'; x++) {
            if (ok(b, r, c, x)) {
                b[r][c] = x;
                if (dfs(b, r, c + 1)) return true;
                b[r][c] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0, 0);
    }
};