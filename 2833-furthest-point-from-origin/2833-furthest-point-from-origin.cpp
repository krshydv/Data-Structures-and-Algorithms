class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, blank = 0;

        for (char c : moves) {
            if (c == 'L')
                left++;
            else if (c == 'R')
                right++;
            else
                blank++;
        }

        return abs(right - left) + blank;
    }
};