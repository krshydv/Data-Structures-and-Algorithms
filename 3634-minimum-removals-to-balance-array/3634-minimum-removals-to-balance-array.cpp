class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int left = 0;
        int best = 0;

        for(int right = 0; right < n; right++) {
            while((long long)nums[right] > (long long)nums[left] * k) {
                left++;
            }
            best = max(best, right - left + 1);
        }

        return n - best;
    }
};