class Solution {
public:
    vector<string> ans;

    void solve(string &s, int index, int left, int right,
               int remLeft, int remRight, string &cur) {

        if (index == s.size()) {
            if (left == right && remLeft == 0 && remRight == 0)
                ans.push_back(cur);
            return;
        }

        char c = s[index];

        if (c == '(' && remLeft > 0) {
            solve(s, index + 1, left, right,
                  remLeft - 1, remRight, cur);
        }

        if (c == ')' && remRight > 0) {
            solve(s, index + 1, left, right,
                  remLeft, remRight - 1, cur);
        }

        if (c == '(') {
            cur.push_back(c);

            solve(s, index + 1, left + 1, right,
                  remLeft, remRight, cur);

            cur.pop_back();
        }
        else if (c == ')') {
            if (left > right) {
                cur.push_back(c);

                solve(s, index + 1, left, right + 1,
                      remLeft, remRight, cur);

                cur.pop_back();
            }
        }
        else {
            cur.push_back(c);

            solve(s, index + 1, left, right,
                  remLeft, remRight, cur);

            cur.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int left = 0;
        int right = 0;

        for (char c : s) {
            if (c == '(') {
                left++;
            }
            else if (c == ')') {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }

        int remLeft = 0;
        int remRight = 0;

        for (char c : s) {
            if (c == '(') {
                remLeft++;
            }
            else if (c == ')' && remLeft > 0) {
                remLeft--;
            }
            else if (c == ')') {
                remRight++;
            }
        }

        string cur;

        solve(s, 0, 0, 0, remLeft, remRight, cur);

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};