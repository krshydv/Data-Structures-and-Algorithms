class Solution {
public:
    void solve(string &s, int i, vector<string> &res) {
        if (i == s.size()) {
            res.push_back(s);
            return;
        }

        if (isalpha(s[i])) {
            s[i] = tolower(s[i]);
            solve(s, i + 1, res);

            s[i] = toupper(s[i]);
            solve(s, i + 1, res);
        } else {
            solve(s, i + 1, res);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        solve(s, 0, res);
        return res;
    }
};