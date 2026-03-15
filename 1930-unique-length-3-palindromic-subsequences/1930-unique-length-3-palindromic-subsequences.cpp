class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int ans = 0;

        for(char c = 'a'; c <= 'z'; c++) {
            int l = s.find(c);
            int r = s.rfind(c);

            if(l == -1 || l == r) continue;

            unordered_set<char> mid;
            for(int i = l + 1; i < r; i++) {
                mid.insert(s[i]);
            }

            ans += mid.size();
        }

        return ans;
    }
};