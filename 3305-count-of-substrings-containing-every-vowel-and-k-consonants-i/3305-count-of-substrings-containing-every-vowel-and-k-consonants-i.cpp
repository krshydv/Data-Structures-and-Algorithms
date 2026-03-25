class Solution {
public:
    int countOfSubstrings(string word, int k) {
        auto isVowel = [&](char c) {
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
        };
        
        int n = word.size(), res = 0;
        
        for (int i = 0; i < n; i++) {
            unordered_map<char,int> mp;
            int cons = 0;
            
            for (int j = i; j < n; j++) {
                if (isVowel(word[j])) mp[word[j]]++;
                else cons++;
                
                if (cons > k) break;
                
                if (mp.size() == 5 && cons == k)
                    res++;
            }
        }
        
        return res;
    }
};