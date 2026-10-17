class Solution {
public:
    static const long long MOD = 1000000007;

    vector<long long> sum, sq, lazy;

    void apply(int node, int l, int r, long long x) {
        long long len = r - l + 1;

        sq[node] = (sq[node] + 2 * x % MOD * sum[node] % MOD + len % MOD * x % MOD * x) % MOD;
        sum[node] = (sum[node] + len % MOD * x) % MOD;
        lazy[node] = (lazy[node] + x) % MOD;
    }

    void push(int node, int l, int r) {
        if (lazy[node] == 0 || l == r)
            return;

        int mid = (l + r) / 2;

        apply(node * 2, l, mid, lazy[node]);
        apply(node * 2 + 1, mid + 1, r, lazy[node]);

        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
        sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        sum.resize(4 * n);
        sq.resize(4 * n);
        lazy.resize(4 * n);

        vector<int> last(100001, -1);

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int p = last[nums[i]];

            update(1, 0, n - 1, p + 1, i);

            ans = (ans + sq[1]) % MOD;

            last[nums[i]] = i;
        }

        return ans;
    }
};