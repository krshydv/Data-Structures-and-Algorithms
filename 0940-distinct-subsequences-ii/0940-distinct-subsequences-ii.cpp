class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        
        vector<long long> last(26, 0);
        long long dp = 1;
        
        for (char c : s) {
            long long newDp = (dp * 2 - last[c - 'a'] + MOD) % MOD;
            last[c - 'a'] = dp;
            dp = newDp;
        }
        
        return (dp - 1 + MOD) % MOD;
    }
};