class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long sum = 0;
        long long curr = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            curr += 1LL * i * nums[i];
        }
        
        long long ans = curr;
        
        for (int k = 1; k < n; k++) {
            curr = curr + sum - 1LL * n * nums[n - k];
            ans = max(ans, curr);
        }
        
        return ans;
    }
};