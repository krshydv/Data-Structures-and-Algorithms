class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {

        auto solve = [&](vector<int>& Astart, vector<int>& Adur,
                         vector<int>& Bstart, vector<int>& Bdur) {

            int m = Bstart.size();

            vector<pair<int,int>> b;
            for(int i = 0; i < m; i++)
                b.push_back({Bstart[i], Bdur[i]});

            sort(b.begin(), b.end());

            vector<int> pref(m), suf(m);

            pref[0] = b[0].second;
            for(int i = 1; i < m; i++)
                pref[i] = min(pref[i - 1], b[i].second);

            suf[m - 1] = b[m - 1].first + b[m - 1].second;
            for(int i = m - 2; i >= 0; i--)
                suf[i] = min(suf[i + 1], b[i].first + b[i].second);

            int ans = INT_MAX;

            for(int i = 0; i < Astart.size(); i++) {
                int finish = Astart[i] + Adur[i];

                int pos = lower_bound(
                    b.begin(),
                    b.end(),
                    make_pair(finish, -1)
                ) - b.begin();

                if(pos > 0)
                    ans = min(ans, finish + pref[pos - 1]);

                if(pos < m)
                    ans = min(ans, suf[pos]);
            }

            return ans;
        };

        return min(
            solve(landStartTime, landDuration, waterStartTime, waterDuration),
            solve(waterStartTime, waterDuration, landStartTime, landDuration)
        );
    }
};