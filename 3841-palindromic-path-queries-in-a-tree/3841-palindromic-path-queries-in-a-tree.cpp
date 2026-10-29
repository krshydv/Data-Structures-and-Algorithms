class Solution {
    vector<vector<int>> g;
    vector<int> parent, depth, size, heavy, head, pos;
    vector<int> seg;
    int timer;

    int dfs(int u, int p) {
        parent[u] = p;
        size[u] = 1;
        int best = -1;
        int bestSize = 0;

        for (int v : g[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            int sub = dfs(v, u);
            size[u] += sub;

            if (sub > bestSize) {
                bestSize = sub;
                best = v;
            }
        }

        heavy[u] = best;
        return size[u];
    }

    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = timer++;

        if (heavy[u] != -1)
            decompose(heavy[u], h);

        for (int v : g[u]) {
            if (v == parent[u] || v == heavy[u]) continue;
            decompose(v, v);
        }
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return 0;

        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) / 2;

        return query(node * 2, l, mid, ql, qr) ^
               query(node * 2 + 1, mid + 1, r, ql, qr);
    }

    int pathQuery(int u, int v, int n) {
        int ans = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            ans ^= query(1, 0, n - 1, pos[head[u]], pos[u]);
            u = parent[head[u]];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        ans ^= query(1, 0, n - 1, pos[u], pos[v]);

        return ans;
    }

    int mask(char c) {
        return 1 << (c - 'a');
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        g.assign(n, {});
        parent.assign(n, -1);
        depth.assign(n, 0);
        size.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        seg.assign(4 * n, 0);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        timer = 0;
        dfs(0, -1);
        decompose(0, 0);

        for (int i = 0; i < n; ++i)
            update(1, 0, n - 1, pos[i], mask(s[i]));

        vector<bool> answer;

        for (string& q : queries) {
            string type;
            int u;
            string x;

            stringstream ss(q);
            ss >> type >> u >> x;

            if (type == "update") {
                s[u] = x[0];
                update(1, 0, n - 1, pos[u], mask(s[u]));
            } else {
                int v = stoi(x);
                int m = pathQuery(u, v, n);

                answer.push_back(m == 0 || (m & (m - 1)) == 0);
            }
        }

        return answer;
    }
};