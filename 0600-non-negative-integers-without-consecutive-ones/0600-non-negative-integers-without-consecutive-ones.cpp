class Solution {
public:
    int findIntegers(int n) {
        vector<int> dp(32);
        dp[0] = 1;
        dp[1] = 2;
        
        for (int i = 2; i < 32; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        int result = 0;
        int prevBit = 0;
        
        for (int i = 30; i >= 0; i--) {
            if (n & (1 << i)) {
                result += dp[i];
                
                if (prevBit == 1) {
                    return result;
                }
                
                prevBit = 1;
            } else {
                prevBit = 0;
            }
        }
        
        return result + 1;
    }
};