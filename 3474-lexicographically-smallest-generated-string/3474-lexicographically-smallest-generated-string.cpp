class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string res(n + m - 1, '?');

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (res[i + j] == '?' || res[i + j] == str2[j]) {
                        res[i + j] = str2[j];
                    } else {
                        return "";
                    }
                }
            }
        }

        for (int i = 0; i < (int)res.size(); i++) {
            if (res[i] == '?') res[i] = 'a';
        }

        auto matches = [&](int i) {
            for (int j = 0; j < m; j++) {
                if (res[i + j] != str2[j]) return false;
            }
            return true;
        };

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F' && matches(i)) {
                bool changed = false;
                for (int j = m - 1; j >= 0; j--) {
                    int pos = i + j;
                    char orig = res[pos];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == orig) continue;
                        res[pos] = c;

                        bool ok = true;
                        for (int k = max(0, pos - m + 1); k <= min(n - 1, pos); k++) {
                            bool eq = true;
                            for (int t = 0; t < m; t++) {
                                if (res[k + t] != str2[t]) {
                                    eq = false;
                                    break;
                                }
                            }
                            if ((str1[k] == 'T' && !eq) || (str1[k] == 'F' && eq)) {
                                ok = false;
                                break;
                            }
                        }

                        if (ok) {
                            changed = true;
                            break;
                        }
                    }
                    if (changed) break;
                    res[pos] = orig;
                }
                if (!changed) return "";
            }
        }

        for (int i = 0; i < n; i++) {
            bool eq = true;
            for (int j = 0; j < m; j++) {
                if (res[i + j] != str2[j]) {
                    eq = false;
                    break;
                }
            }
            if ((str1[i] == 'T' && !eq) || (str1[i] == 'F' && eq)) return "";
        }

        return res;
    }
};