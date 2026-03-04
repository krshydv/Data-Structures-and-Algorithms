class Solution {
public:
    bool check(int x) {
        vector<int> freq(10,0);
        
        while(x){
            freq[x % 10]++;
            x /= 10;
        }
        
        for(int i = 0; i < 10; i++){
            if(freq[i] != 0 && freq[i] != i) return false;
        }
        
        return true;
    }

    int nextBeautifulNumber(int n) {
        int x = n + 1;
        
        while(true){
            if(check(x)) return x;
            x++;
        }
    }
};