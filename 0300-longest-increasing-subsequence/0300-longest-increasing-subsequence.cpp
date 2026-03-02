class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;

        for (int x : nums) {
            auto it = lower_bound(temp.begin(), temp.end(), x);
            if (it == temp.end()) {
                temp.push_back(x);
            } else {
                *it = x;
            }
        }

        return temp.size();
    }
};