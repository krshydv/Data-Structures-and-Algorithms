#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> p, r;
    DSU(int n) : p(n), r(n, 0) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) ++r[a];
        return true;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int mx = 0;
        for (auto& e : edges) mx = max(mx, e[2]);
        int lo = 0, hi = mx * 2, ans = -1;
        auto ok = [&](int T) -> bool {
            DSU dsu(n);
            int used = 0;
            int upgrades = 0;
            for (auto& e : edges) if (e[3] == 1) {
                if (e[2] < T) return false;
                if (!dsu.unite(e[0], e[1])) return false;
                ++used;
            }
            vector<array<int,3>> cand;
            for (auto& e : edges) if (e[3] == 0) {
                if (e[2] >= T) cand.push_back({0, e[0], e[1]});
                else if (e[2] * 2 >= T) cand.push_back({1, e[0], e[1]});
            }
            sort(cand.begin(), cand.end(), [](auto& a, auto& b){ return a[0] < b[0]; });
            for (auto& c : cand) {
                if (used == n - 1) break;
                if (dsu.unite(c[1], c[2])) {
                    upgrades += c[0];
                    if (upgrades > k) return false;
                    ++used;
                }
            }
            if (used != n - 1) return false;
            int root = dsu.find(0);
            for (int i = 1; i < n; ++i) if (dsu.find(i) != root) return false;
            return upgrades <= k;
        };
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (ok(mid)) { ans = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        return ans;
    }
};