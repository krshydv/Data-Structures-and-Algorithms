class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> power(n, 0), pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + stations[i];
        }

        for (int i = 0; i < n; i++) {
            int l = max(0, i - r);
            int rr = min(n - 1, i + r);
            power[i] = pref[rr + 1] - pref[l];
        }

        long long low = 0, high = 1e14, ans = 0;

        auto can = [&](long long mid) {
            vector<long long> temp(power), add(n, 0);
            long long used = 0, curr = 0;

            for (int i = 0; i < n; i++) {
                if (i > r) curr -= add[i - r - 1];
                long long need = max(0LL, mid - (temp[i] + curr));
                if (need > 0) {
                    used += need;
                    if (used > k) return false;
                    curr += need;
                    int pos = min(n - 1, i + r);
                    add[pos] += need;
                }
            }
            return true;
        };

        while (low <= high) {
            long long mid = (low + high) / 2;
            if (can(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};