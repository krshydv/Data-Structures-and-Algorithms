class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        vector<string> a, b;
        stringstream ss1(s1), ss2(s2);
        string word;
        
        while (ss1 >> word) a.push_back(word);
        while (ss2 >> word) b.push_back(word);
        
        int i = 0, j = 0;
        
        while (i < a.size() && i < b.size() && a[i] == b[i])
            i++;
        
        while (j < a.size() - i && j < b.size() - i && 
               a[a.size() - 1 - j] == b[b.size() - 1 - j])
            j++;
        
        return i + j == min(a.size(), b.size());
    }
};