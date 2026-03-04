class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = n;
        
        while(n >>= 1) {
            ans ^= n;
        }
        
        return ans;
    }
};