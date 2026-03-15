class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        
        unordered_map<long long,long long> right;
        for(int x : nums) right[x]++;
        
        unordered_map<long long,long long> left;
        long long ans = 0;
        
        for(int j = 0; j < n; j++) {
            right[nums[j]]--;
            
            long long a = nums[j] * 2;
            long long c = nums[j] * 2;
            
            long long leftCount = left[a];
            long long rightCount = right[c];
            
            ans = (ans + (leftCount * rightCount) % MOD) % MOD;
            
            left[nums[j]]++;
        }
        
        return ans;
    }
};