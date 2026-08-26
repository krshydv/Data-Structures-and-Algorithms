class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, ones = 0;
        string ans = "";

        for (int right = 0; right < n; right++) {
            ones += s[right] - '0';

            while (ones > k) {
                ones -= s[left] - '0';
                left++;
            }

            while (left <= right && ones == k && s[left] == '0') {
                left++;
            }

            if (ones == k) {
                string curr = s.substr(left, right - left + 1);

                if (ans.empty() || curr.size() < ans.size() ||
                    (curr.size() == ans.size() && curr < ans)) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};