class Solution {
public:
    string sortString(string s) {
        int freq[26] = {0};
        for (char c : s) freq[c - 'a']++;

        string result;
        while (result.size() < s.size()) {
            for (int i = 0; i < 26; i++) {
                if (freq[i] > 0) {
                    result += ('a' + i);
                    freq[i]--;
                }
            }
            for (int i = 25; i >= 0; i--) {
                if (freq[i] > 0) {
                    result += ('a' + i);
                    freq[i]--;
                }
            }
        }

        return result;
    }
};