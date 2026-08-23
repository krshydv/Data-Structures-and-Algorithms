class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int diff = 0;
        int question = 0;

        for (int i = 0; i < n; i++) {
            if (num[i] == '?') {
                if (i < n / 2) {
                    question++;
                } else {
                    question--;
                }
            } else {
                if (i < n / 2) {
                    diff += num[i] - '0';
                } else {
                    diff -= num[i] - '0';
                }
            }
        }

        if ((question & 1) != 0) {
            return true;
        }

        return diff != (-question / 2) * 9;
    }
};