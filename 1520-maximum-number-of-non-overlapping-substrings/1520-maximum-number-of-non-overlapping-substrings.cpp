class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, s.size()), last(26, -1);

        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<string> answer;
        int previousEnd = -1;

        for (int start = 0; start < s.size(); start++) {
            int c = s[start] - 'a';

            if (first[c] != start) {
                continue;
            }

            int end = last[c];
            bool valid = true;

            for (int i = start; i <= end; i++) {
                int current = s[i] - 'a';

                if (first[current] < start) {
                    valid = false;
                    break;
                }

                end = max(end, last[current]);
            }

            if (!valid) {
                continue;
            }

            if (start > previousEnd) {
                answer.push_back(s.substr(start, end - start + 1));
            } else {
                answer.back() = s.substr(start, end - start + 1);
            }

            previousEnd = end;
        }

        return answer;
    }
};