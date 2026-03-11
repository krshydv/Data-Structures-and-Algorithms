class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();

        for (int len = 1; len <= n; len++) {
            if (n % len != 0) continue;

            int freq[26] = {0};
            for (int i = 0; i < len; i++)
                freq[s[i] - 'a']++;

            bool valid = true;
            for (int i = len; i < n; i += len) {
                int cur[26] = {0};
                for (int j = i; j < i + len; j++)
                    cur[s[j] - 'a']++;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] != cur[k]) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) break;
            }

            if (valid) return len;
        }

        return n;
    }
};