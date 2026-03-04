class Solution {
public:
    int longest(vector<int>& a) {
        sort(a.begin(), a.end());
        int ans = 1, cur = 1;

        for(int i = 1; i < a.size(); i++) {
            if(a[i] == a[i-1] + 1)
                cur++;
            else
                cur = 1;
            ans = max(ans, cur);
        }

        return ans + 1;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int h = longest(hBars);
        int v = longest(vBars);

        int side = min(h, v);
        return side * side;
    }
};