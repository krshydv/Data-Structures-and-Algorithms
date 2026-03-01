class Solution {
public:
    int longestSubstring(string s, int k) {
        return solve(s, 0, s.size(), k);
    }
    
    int solve(string& s, int left, int right, int k) {
        if (right - left < k) return 0;
        
        vector<int> freq(26, 0);
        for (int i = left; i < right; i++) {
            freq[s[i] - 'a']++;
        }
        
        for (int i = left; i < right; i++) {
            if (freq[s[i] - 'a'] < k) {
                int j = i + 1;
                while (j < right && freq[s[j] - 'a'] < k) j++;
                return max(solve(s, left, i, k), solve(s, j, right, k));
            }
        }
        
        return right - left;
    }
};