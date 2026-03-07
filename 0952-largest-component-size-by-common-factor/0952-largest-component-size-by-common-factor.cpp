class Solution {
public:
    vector<int> parent, size;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

    int largestComponentSize(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        parent.resize(m + 1);
        size.resize(m + 1, 1);

        for (int i = 0; i <= m; i++) parent[i] = i;

        for (int x : nums) {
            for (int f = 2; f * f <= x; f++) {
                if (x % f == 0) {
                    unite(x, f);
                    unite(x, x / f);
                }
            }
        }

        unordered_map<int, int> count;
        int ans = 0;

        for (int x : nums) {
            int root = find(x);
            ans = max(ans, ++count[root]);
        }

        return ans;
    }
};