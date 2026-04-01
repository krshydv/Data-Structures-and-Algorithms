class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int x : nums) {
            int cnt = 0, sum = 0;

            for (int i = 1; i * i <= x; i++) {
                if (x % i == 0) {
                    int j = x / i;
                    if (i == j) {
                        cnt++;
                        sum += i;
                    } else {
                        cnt += 2;
                        sum += i + j;
                    }
                }
                if (cnt > 4) break;
            }

            if (cnt == 4) ans += sum;
        }

        return ans;
    }
};