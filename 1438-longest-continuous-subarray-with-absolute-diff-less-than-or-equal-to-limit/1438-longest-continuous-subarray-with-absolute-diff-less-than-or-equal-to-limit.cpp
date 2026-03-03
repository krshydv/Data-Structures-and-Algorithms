class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxd, mind;
        int left = 0, ans = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            while (!maxd.empty() && nums[maxd.back()] < nums[right])
                maxd.pop_back();
            while (!mind.empty() && nums[mind.back()] > nums[right])
                mind.pop_back();
            
            maxd.push_back(right);
            mind.push_back(right);
            
            while (nums[maxd.front()] - nums[mind.front()] > limit) {
                if (maxd.front() == left) maxd.pop_front();
                if (mind.front() == left) mind.pop_front();
                left++;
            }
            
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};