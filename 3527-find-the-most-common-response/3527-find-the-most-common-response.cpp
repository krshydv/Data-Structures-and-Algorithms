class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> mp;
        
        for (auto &day : responses) {
            unordered_set<string> st(day.begin(), day.end());
            for (auto &s : st) {
                mp[s]++;
            }
        }
        
        string ans = "";
        int maxi = 0;
        
        for (auto &p : mp) {
            if (p.second > maxi || (p.second == maxi && p.first < ans)) {
                maxi = p.second;
                ans = p.first;
            }
        }
        
        return ans;
    }
};