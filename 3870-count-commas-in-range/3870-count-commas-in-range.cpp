class Solution {
public:
    long long countCommas(int n) {
        long long ans = 0;

        if (n >= 1000)
            ans += n - 999;

        if (n >= 1000000)
            ans += n - 999999;

        if (n >= 1000000000)
            ans += n - 999999999;

        return ans;
    }
};