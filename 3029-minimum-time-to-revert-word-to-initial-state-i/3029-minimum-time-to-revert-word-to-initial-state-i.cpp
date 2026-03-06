class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();

        for(int t = 1; t * k < n; t++) {
            if(word.substr(t * k) == word.substr(0, n - t * k)) {
                return t;
            }
        }

        return (n + k - 1) / k;
    }
};