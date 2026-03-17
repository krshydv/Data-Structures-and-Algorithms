class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> h(n);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                h[j] = matrix[i][j] ? h[j] + 1 : 0;

            vector<int> t = h;
            sort(t.begin(), t.end(), greater<int>());

            for (int j = 0; j < n; j++)
                ans = max(ans, t[j] * (j + 1));
        }

        return ans;
    }
};