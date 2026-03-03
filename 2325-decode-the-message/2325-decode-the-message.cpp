class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<char> mp(26, 0);
        vector<bool> used(26, false);
        
        char cur = 'a';
        for (char c : key) {
            if (c != ' ' && !used[c - 'a']) {
                mp[c - 'a'] = cur++;
                used[c - 'a'] = true;
            }
        }
        
        string ans = "";
        for (char c : message) {
            if (c == ' ') ans += ' ';
            else ans += mp[c - 'a'];
        }
        
        return ans;
    }
};