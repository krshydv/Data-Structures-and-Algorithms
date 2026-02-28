class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int starIndex = -1, matchIndex = 0;

        while (i < s.size()) {
            if (j < p.size() && (p[j] == s[i] || p[j] == '?')) {
                i++;
                j++;
            } 
            else if (j < p.size() && p[j] == '*') {
                starIndex = j;
                matchIndex = i;
                j++;
            } 
            else if (starIndex != -1) {
                j = starIndex + 1;
                matchIndex++;
                i = matchIndex;
            } 
            else {
                return false;
            }
        }

        while (j < p.size() && p[j] == '*') {
            j++;
        }

        return j == p.size();
    }
};