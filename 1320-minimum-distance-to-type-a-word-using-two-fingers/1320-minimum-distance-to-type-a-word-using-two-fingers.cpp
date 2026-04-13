class Solution {
public:
    int dist(int a, int b) {
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        int n = word.size();
        vector<int> dp(26, 0);
        int total = 0;

        for(int i = 1; i < n; i++) {
            int cur = word[i] - 'A';
            int prev = word[i - 1] - 'A';

            int d = dist(prev, cur);
            total += d;

            vector<int> newdp = dp;

            for(int j = 0; j < 26; j++) {
                newdp[prev] = max(newdp[prev], dp[j] + d - dist(j, cur));
            }

            dp = newdp;
        }

        int maxSave = 0;
        for(int x : dp) maxSave = max(maxSave, x);

        return total - maxSave;
    }
};