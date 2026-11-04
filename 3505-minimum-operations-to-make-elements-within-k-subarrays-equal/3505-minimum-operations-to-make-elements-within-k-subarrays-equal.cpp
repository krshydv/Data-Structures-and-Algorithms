class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<long long> lo, hi;
        long long sumLo = 0, sumHi = 0;

        auto add = [&](long long v) {
            if (lo.empty() || v <= *lo.rbegin()) {
                lo.insert(v);
                sumLo += v;
            } else {
                hi.insert(v);
                sumHi += v;
            }

            while (lo.size() > hi.size() + 1) {
                auto it = prev(lo.end());
                long long v = *it;
                lo.erase(it);
                sumLo -= v;
                hi.insert(v);
                sumHi += v;
            }

            while (lo.size() < hi.size()) {
                auto it = hi.begin();
                long long v = *it;
                hi.erase(it);
                sumHi -= v;
                lo.insert(v);
                sumLo += v;
            }
        };

        auto remove = [&](long long v) {
            auto it = lo.find(v);

            if (it != lo.end()) {
                lo.erase(it);
                sumLo -= v;
            } else {
                it = hi.find(v);
                hi.erase(it);
                sumHi -= v;
            }

            while (lo.size() > hi.size() + 1) {
                auto jt = prev(lo.end());
                long long val = *jt;
                lo.erase(jt);
                sumLo -= val;
                hi.insert(val);
                sumHi += val;
            }

            while (lo.size() < hi.size()) {
                auto jt = hi.begin();
                long long val = *jt;
                hi.erase(jt);
                sumHi -= val;
                lo.insert(val);
                sumLo += val;
            }
        };

        vector<long long> cost(n - x + 1);

        for (int i = 0; i < x; ++i)
            add(nums[i]);

        auto getCost = [&]() -> long long {
            long long med = *lo.rbegin();

            long long left = med * (long long)lo.size() - sumLo;
            long long right = sumHi - med * (long long)hi.size();

            return left + right;
        };

        cost[0] = getCost();

        for (int i = x; i < n; ++i) {
            add(nums[i]);
            remove(nums[i - x]);
            cost[i - x + 1] = getCost();
        }

        const long long INF = 4e18;

        vector<long long> prev(n + 1, 0), cur(n + 1, INF);

        for (int used = 1; used <= k; ++used) {
            fill(cur.begin(), cur.end(), INF);

            for (int i = 1; i <= n; ++i) {
                cur[i] = cur[i - 1];

                if (i >= x && prev[i - x] != INF) {
                    cur[i] = min(
                        cur[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(cur);
        }

        return prev[n];
    }
};