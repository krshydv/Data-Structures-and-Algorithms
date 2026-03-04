class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string prev = "";

        for(string w : words) {
            string t = w;
            sort(t.begin(), t.end());

            if(t != prev) {
                ans.push_back(w);
                prev = t;
            }
        }

        return ans;
    }
};