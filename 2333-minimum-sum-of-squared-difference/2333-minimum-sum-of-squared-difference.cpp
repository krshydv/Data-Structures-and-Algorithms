class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff(nums1.size());
        long long total = 0;

        for (int i = 0; i < nums1.size(); i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
        }

        long long k = (long long)k1 + k2;

        if (k >= total) return 0;

        int left = 0, right = *max_element(diff.begin(), diff.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long needed = 0;

            for (int d : diff) {
                if (d > mid) needed += d - mid;
            }

            if (needed <= k) right = mid;
            else left = mid + 1;
        }

        int level = left;
        long long ans = 0;
        long long remaining = k;

        for (int d : diff) {
            if (d > level) {
                remaining -= d - level;
                ans += 1LL * level * level;
            } else {
                ans += 1LL * d * d;
            }
        }

        for (int d : diff) {
            if (remaining > 0 && d >= level) {
                ans -= 2LL * level - 1;
                remaining--;
            }
        }

        return ans;
    }
};