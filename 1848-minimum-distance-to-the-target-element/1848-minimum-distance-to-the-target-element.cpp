class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        
        for(int d = 0; d < n; d++) {
            if(start - d >= 0 && nums[start - d] == target) return d;
            if(start + d < n && nums[start + d] == target) return d;
        }
        
        return -1;
    }
};