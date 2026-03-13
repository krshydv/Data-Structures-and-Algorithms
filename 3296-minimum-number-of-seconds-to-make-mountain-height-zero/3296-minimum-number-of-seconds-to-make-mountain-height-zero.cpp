#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long h = mountainHeight;
        long long tmin = *min_element(workerTimes.begin(), workerTimes.end());
        long long hi = tmin * h * (h + 1LL) / 2;
        long long lo = 0;

        auto can = [&](long long T) -> bool {
            long long removed = 0;
            for (long long w : workerTimes) {
                long double disc = 1.0L + 8.0L * (long double)T / (long double)w;
                long long k = (long long)((sqrt(disc) - 1.0L) / 2.0L);
                while (k > 0 && (__int128)w * k * (k + 1) / 2 > T) --k;
                while ((__int128)w * (k + 1) * (k + 2) / 2 <= T) ++k;
                removed += k;
                if (removed >= h) return true;
            }
            return removed >= h;
        };

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (can(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};