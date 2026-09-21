class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k);
        vector<long long> dp(k);

        for (int num : nums) {
            int x = num % k;
            vector<long long> next(k);

            next[x]++;

            for (int r = 0; r < k; r++) {
                next[(r * x) % k] += dp[r];
            }

            for (int r = 0; r < k; r++) {
                result[r] += next[r];
            }

            dp = next;
        }

        return result;
    }
};