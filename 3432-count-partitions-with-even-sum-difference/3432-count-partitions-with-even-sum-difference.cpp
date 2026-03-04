class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long sum = 0;
        for(int x : nums) sum += x;

        if(sum % 2) return 0;
        return nums.size() - 1;
    }
};