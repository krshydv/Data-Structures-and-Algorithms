class Solution {
public:
    vector<string> res;
    
    void solve(int n, string curr) {
        if(curr.size() == n) {
            res.push_back(curr);
            return;
        }
        
        for(char ch : {'a','b','c'}) {
            if(curr.empty() || curr.back() != ch) {
                solve(n, curr + ch);
            }
        }
    }
    
    string getHappyString(int n, int k) {
        solve(n, "");
        
        if(res.size() < k) return "";
        
        return res[k-1];
    }
};