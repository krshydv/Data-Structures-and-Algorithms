class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n + 1);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        vector<int> dp(n + 1);
        vector<long long> last(n + 1);
        deque<int> dq;
        dq.push_back(0);

        for (int i = 1; i <= n; i++) {
            while (dq.size() >= 2 && prefix[dq[1]] + last[dq[1]] <= prefix[i])
                dq.pop_front();

            int j = dq.front();
            dp[i] = dp[j] + 1;
            last[i] = prefix[i] - prefix[j];

            while (!dq.empty() && prefix[dq.back()] + last[dq.back()] >= prefix[i] + last[i])
                dq.pop_back();

            dq.push_back(i);
        }

        return dp[n];
    }
};