class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;

        vector<int> gain(n);

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            minPrice = min(minPrice, price);

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % factor == 0) {
                    gain[i]++;
                }
            }
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            int value = gain[i] + 1;

            for (int b = budget; b >= price; b--) {
                dp[b] = max(dp[b], dp[b - price] + value);
            }
        }

        int ans = 0;

        for (int spent = 0; spent <= budget; spent++) {
            int extra = (budget - spent) / minPrice;
            ans = max(ans, dp[spent] + extra);
        }

        return ans;
    }
};