class Solution {
public:
    int minOperations(string s) {
        int c1 = 0, c2 = 0;

        for(int i = 0; i < s.size(); i++) {
            char e1 = (i % 2 == 0) ? '0' : '1';
            char e2 = (i % 2 == 0) ? '1' : '0';

            if(s[i] != e1) c1++;
            if(s[i] != e2) c2++;
        }

        return min(c1, c2);
    }
};