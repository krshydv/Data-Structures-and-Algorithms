class Solution {
    struct State {
        long long val;
        int l, r;
        bool operator<(const State& other) const {
            return val < other.val;
        }
    };

public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);

        sort(ord.begin(), ord.end(), [&](int a, int b) {
            if (nums[a] != nums[b]) return nums[a] < nums[b];
            return a < b;
        });

        auto key = [&](int l, int r) {
            return (long long)l * n + r;
        };

        unordered_map<long long, pair<int, int>> mp;

        auto getEnds = [&](int l, int r, int i, int j) {
            while (i < n && (ord[i] < l || ord[i] > r)) i++;
            while (j >= 0 && (ord[j] < l || ord[j] > r)) j--;
            return pair<int, int>{i, j};
        };

        priority_queue<State> pq;

        mp[key(0, n - 1)] = {0, n - 1};

        pq.push({
            (long long)nums[ord[n - 1]] - nums[ord[0]],
            0,
            n - 1
        });

        long long ans = 0;

        while (k > 0) {
            auto cur = pq.top();
            pq.pop();

            auto [i, j] = mp[key(cur.l, cur.r)];

            int mnPos = ord[i];
            int mxPos = ord[j];

            int left = min(mnPos, mxPos);
            int right = max(mnPos, mxPos);

            long long cnt = 1LL * (left - cur.l + 1) * (cur.r - right + 1);
            cnt = min(cnt, (long long)k);

            ans += cnt * cur.val;
            k -= cnt;

            if (left + 1 <= cur.r) {
                long long nk = key(left + 1, cur.r);

                if (!mp.count(nk)) {
                    auto p = getEnds(left + 1, cur.r, i, j);
                    mp[nk] = p;

                    pq.push({
                        (long long)nums[ord[p.second]] - nums[ord[p.first]],
                        left + 1,
                        cur.r
                    });
                }
            }

            if (cur.l <= right - 1) {
                long long nk = key(cur.l, right - 1);

                if (!mp.count(nk)) {
                    auto p = getEnds(cur.l, right - 1, i, j);
                    mp[nk] = p;

                    pq.push({
                        (long long)nums[ord[p.second]] - nums[ord[p.first]],
                        cur.l,
                        right - 1
                    });
                }
            }
        }

        return ans;
    }
};