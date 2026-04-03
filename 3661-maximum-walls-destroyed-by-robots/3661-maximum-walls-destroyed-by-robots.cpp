class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int,int>> r(n);
        for(int i = 0; i < n; i++) r[i] = {robots[i], distance[i]};
        sort(r.begin(), r.end());
        sort(walls.begin(), walls.end());

        vector<pair<int,int>> L(n), R(n);
        for(int i = 0; i < n; i++){
            int pos = r[i].first, dist = r[i].second;
            int lo = pos - dist;
            if(i > 0) lo = max(lo, r[i-1].first);
            int hi = pos + dist;
            if(i < n-1) hi = min(hi, r[i+1].first);
            L[i] = {(int)(lower_bound(walls.begin(),walls.end(),lo)-walls.begin()),
                    (int)(upper_bound(walls.begin(),walls.end(),pos)-walls.begin())};
            R[i] = {(int)(lower_bound(walls.begin(),walls.end(),pos)-walls.begin()),
                    (int)(upper_bound(walls.begin(),walls.end(),hi)-walls.begin())};
        }

        auto cnt = [](pair<int,int> p){ return p.second - p.first; };
        auto overlap = [](pair<int,int> a, pair<int,int> b){
            return max(0, min(a.second,b.second)-max(a.first,b.first));
        };

        vector<array<int,2>> dp(n);
        dp[0][0] = cnt(L[0]);
        dp[0][1] = cnt(R[0]);
        for(int i = 1; i < n; i++){
            for(int d : {0,1}){
                auto& cur = (d==0?L[i]:R[i]);
                dp[i][d] = 0;
                for(int pd : {0,1}){
                    auto& prev = (pd==0?L[i-1]:R[i-1]);
                    int val = dp[i-1][pd] + cnt(cur) - overlap(cur, prev);
                    dp[i][d] = max(dp[i][d], val);
                }
            }
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};