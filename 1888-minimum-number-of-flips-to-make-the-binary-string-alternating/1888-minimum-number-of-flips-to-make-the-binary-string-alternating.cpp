class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string t = s + s;

        string a = "", b = "";
        for (int i = 0; i < 2 * n; i++) {
            a += (i % 2 == 0 ? '0' : '1');
            b += (i % 2 == 0 ? '1' : '0');
        }

        int ans = INT_MAX;
        int d1 = 0, d2 = 0, l = 0;

        for (int r = 0; r < 2 * n; r++) {
            if (t[r] != a[r]) d1++;
            if (t[r] != b[r]) d2++;

            if (r - l + 1 > n) {
                if (t[l] != a[l]) d1--;
                if (t[l] != b[l]) d2--;
                l++;
            }

            if (r - l + 1 == n) {
                ans = min(ans, min(d1, d2));
            }
        }

        return ans;
    }
};