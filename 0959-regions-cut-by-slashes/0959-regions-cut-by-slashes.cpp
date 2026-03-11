class Solution {
public:
    int parent[900 * 4];

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) parent[a] = b;
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int total = n * n * 4;

        for (int i = 0; i < total; i++)
            parent[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int base = (i * n + j) * 4;

                if (grid[i][j] == ' ') {
                    unite(base, base + 1);
                    unite(base + 1, base + 2);
                    unite(base + 2, base + 3);
                } else if (grid[i][j] == '/') {
                    unite(base, base + 3);
                    unite(base + 1, base + 2);
                } else {
                    unite(base, base + 1);
                    unite(base + 2, base + 3);
                }

                if (j + 1 < n)
                    unite(base + 1, (i * n + j + 1) * 4 + 3);

                if (i + 1 < n)
                    unite(base + 2, ((i + 1) * n + j) * 4);
            }
        }

        int regions = 0;
        for (int i = 0; i < total; i++) {
            if (find(i) == i) regions++;
        }
        return regions;
    }
};