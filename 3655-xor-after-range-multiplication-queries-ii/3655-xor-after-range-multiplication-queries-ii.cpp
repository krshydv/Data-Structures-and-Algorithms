class Solution {
public:
    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        const long long MOD = 1000000007;

        vector<long long> mul(n, 1);

        map<pair<int,int>, vector<long long>> diff;

        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2];
            long long v = q[3];
            int offset = l % k;
            auto key = make_pair(k, offset);
            if (!diff.count(key))
                diff[key].assign((n - offset + k - 1) / k + 2, 1);
            int s = (l - offset) / k;
            int e = (r - offset) / k;
            diff[key][s] = diff[key][s] * v % MOD;
            diff[key][e + 1] = diff[key][e + 1] * power(v, MOD - 2, MOD) % MOD;
        }

        for (auto& [key, d] : diff) {
            auto [k, offset] = key;
            long long cur = 1;
            for (int slot = 0; slot < (int)d.size() - 1; slot++) {
                cur = cur * d[slot] % MOD;
                int idx = offset + slot * k;
                if (idx < n)
                    mul[idx] = mul[idx] * cur % MOD;
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++)
            result ^= (int)((__int128)nums[i] * mul[i] % MOD);
        return result;
    }
};