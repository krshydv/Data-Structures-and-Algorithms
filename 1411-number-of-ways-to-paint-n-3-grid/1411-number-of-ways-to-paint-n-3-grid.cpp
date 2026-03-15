class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1e9 + 7;
        
        long long aba = 6;
        long long abc = 6;
        
        for(int i = 2; i <= n; i++) {
            long long new_aba = (aba * 3 + abc * 2) % MOD;
            long long new_abc = (aba * 2 + abc * 2) % MOD;
            
            aba = new_aba;
            abc = new_abc;
        }
        
        return (aba + abc) % MOD;
    }
};