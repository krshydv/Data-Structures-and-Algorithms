class Solution {
public:
    static constexpr long long MOD = 1'000'000'007;

    long long modPow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = result * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return result;
    }

    int numberOfSets(int n, int k) {
        int total = n + k - 1;  // Need C(n + k - 1, 2k)

        vector<long long> fact(total + 1), invFact(total + 1);
        fact[0] = 1;

        for (int i = 1; i <= total; ++i)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[total] = modPow(fact[total], MOD - 2);

        for (int i = total; i >= 1; --i)
            invFact[i - 1] = invFact[i] * i % MOD;

        return fact[total] * invFact[2 * k] % MOD * invFact[total - 2 * k] % MOD;
    }
};