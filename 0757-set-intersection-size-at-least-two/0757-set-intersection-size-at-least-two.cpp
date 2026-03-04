class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        int a = -1, b = -1;
        int ans = 0;

        for(auto &in : intervals){
            int l = in[0], r = in[1];

            if(l > b){
                ans += 2;
                a = r - 1;
                b = r;
            }
            else if(l > a){
                ans += 1;
                a = b;
                b = r;
            }
        }

        return ans;
    }
};