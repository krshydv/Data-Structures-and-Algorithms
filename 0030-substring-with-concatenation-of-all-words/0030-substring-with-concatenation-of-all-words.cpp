class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty()) return res;

        int n = s.size();
        int m = words.size();
        int w = words[0].size();
        int total = m * w;

        unordered_map<string,int> need;
        for (auto &x : words) need[x]++;

        for (int i = 0; i < w; i++) {
            unordered_map<string,int> cur;
            int left = i;
            int cnt = 0;

            for (int j = i; j + w <= n; j += w) {
                string t = s.substr(j, w);
                if (need.count(t)) {
                    cur[t]++;
                    cnt++;

                    while (cur[t] > need[t]) {
                        string rm = s.substr(left, w);
                        cur[rm]--;
                        left += w;
                        cnt--;
                    }

                    if (cnt == m) {
                        res.push_back(left);
                        string rm = s.substr(left, w);
                        cur[rm]--;
                        left += w;
                        cnt--;
                    }
                } else {
                    cur.clear();
                    cnt = 0;
                    left = j + w;
                }
            }
        }

        return res;
    }
};