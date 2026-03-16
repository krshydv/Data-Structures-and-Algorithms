class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                
                int left = 0, right = 0;

                for(int j = 0; j < i; j++) left += nums[j];
                for(int j = i + 1; j < n; j++) right += nums[j];

                if(left == right) ans += 2;
                else if(abs(left - right) == 1) ans += 1;
            }
        }

        return ans;
    }
};