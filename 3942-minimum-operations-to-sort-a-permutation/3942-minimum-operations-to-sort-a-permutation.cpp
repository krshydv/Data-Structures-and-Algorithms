class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = find(nums.begin(), nums.end(), 0) - nums.begin();
        int ans = INT_MAX;

        auto check = [&](int step) {
            for (int i = 1; i < n; i++) {
                int a = (zero + (i - 1) * step + n) % n;
                int b = (zero + i * step + n) % n;

                if (nums[a] > nums[b])
                    return false;
            }
            return true;
        };

        if (check(1)) {
            ans = min(ans, zero);
            ans = min(ans, n - zero + 2);
        }

        if (check(-1)) {
            ans = min(ans, zero + 2);
            ans = min(ans, n - zero);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};