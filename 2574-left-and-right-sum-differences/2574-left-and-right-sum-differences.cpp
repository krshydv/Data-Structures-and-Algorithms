class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0, right = 0;
        for (int x : nums) right += x;
        for (int i = 0; i < n; i++) {
            right -= nums[i];
            ans[i] = abs(left - right);
            left += nums[i];
        }
        return ans;
    }
};