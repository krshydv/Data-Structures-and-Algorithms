class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string t = "";

            for (int i = 0; i < s.size(); i += k) {
                int sum = 0;

                for (int j = i; j < min(i + k, (int)s.size()); j++) {
                    sum += s[j] - '0';
                }

                t += to_string(sum);
            }

            s = t;
        }

        return s;
    }
};