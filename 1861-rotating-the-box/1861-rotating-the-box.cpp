class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        for (int row = 0; row < m; row++) {
            int write = n - 1;

            for (int col = n - 1; col >= 0; col--) {
                if (boxGrid[row][col] == '*') {
                    write = col - 1;
                } else if (boxGrid[row][col] == '#') {
                    swap(boxGrid[row][col], boxGrid[row][write]);
                    write--;
                }
            }
        }

        vector<vector<char>> result(n, vector<char>(m));

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                result[col][m - 1 - row] = boxGrid[row][col];
            }
        }

        return result;
    }
};