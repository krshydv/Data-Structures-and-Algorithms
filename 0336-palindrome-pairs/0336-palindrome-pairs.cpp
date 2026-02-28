class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;
        vector<vector<int>> result;

        for (int i = 0; i < words.size(); i++) {
            mp[words[i]] = i;
        }

        for (int i = 0; i < words.size(); i++) {
            string word = words[i];

            for (int j = 0; j <= word.size(); j++) {
                string left = word.substr(0, j);
                string right = word.substr(j);

                if (isPalindrome(left)) {
                    string revRight = right;
                    reverse(revRight.begin(), revRight.end());
                    if (mp.count(revRight) && mp[revRight] != i) {
                        result.push_back({mp[revRight], i});
                    }
                }

                if (j != word.size() && isPalindrome(right)) {
                    string revLeft = left;
                    reverse(revLeft.begin(), revLeft.end());
                    if (mp.count(revLeft) && mp[revLeft] != i) {
                        result.push_back({i, mp[revLeft]});
                    }
                }
            }
        }

        return result;
    }

private:
    bool isPalindrome(const string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};