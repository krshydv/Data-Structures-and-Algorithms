class Solution {
public:
    string s;
    int i;

    set<string> parseExpression() {
        set<string> res = parseTerm();

        while (i < s.size() && s[i] == ',') {
            i++;
            set<string> nxt = parseTerm();
            res.insert(nxt.begin(), nxt.end());
        }

        return res;
    }

    set<string> parseTerm() {
        set<string> res = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> cur = parseFactor();
            set<string> nxt;

            for (const string& a : res) {
                for (const string& b : cur) {
                    nxt.insert(a + b);
                }
            }

            res = move(nxt);
        }

        return res;
    }

    set<string> parseFactor() {
        if (s[i] == '{') {
            i++;
            set<string> res = parseExpression();
            i++;
            return res;
        }

        return {string(1, s[i++])};
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> res = parseExpression();

        return vector<string>(res.begin(), res.end());
    }
};