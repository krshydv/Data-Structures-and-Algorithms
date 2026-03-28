class Solution {
    struct DSU {
        vector<int> p, r;
        DSU(int n) : p(n), r(n, 0) { iota(p.begin(), p.end(), 0); }
        int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
        void unite(int a, int b) {
            a = find(a); b = find(b);
            if (a == b) return;
            if (r[a] < r[b]) swap(a, b);
            p[b] = a;
            if (r[a] == r[b]) ++r[a];
        }
    };
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        DSU dsu(n);
        for (int i = 0; i < n; ++i) {
            if (lcp[i][i] != n - i) return "";
            for (int j = i + 1; j < n; ++j) {
                if (lcp[i][j] > 0) dsu.unite(i, j);
            }
        }
        vector<char> repChar(n, 0);
        char cur = 'a';
        for (int i = 0; i < n; ++i) {
            int r = dsu.find(i);
            if (!repChar[r]) {
                if (cur > 'z') return "";
                repChar[r] = cur++;
            }
        }
        string s(n, 'a');
        for (int i = 0; i < n; ++i) s[i] = repChar[dsu.find(i)];

        vector<vector<int>> check(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (s[i] == s[j]) check[i][j] = 1 + check[i + 1][j + 1];
            }
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (check[i][j] != lcp[i][j]) return "";
        return s;
    }
};