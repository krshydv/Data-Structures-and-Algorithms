class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;

        for(int x : nums){
            mp[x]++;
            if(mp[x] == 2) ans.push_back(x);
        }

        return ans;
    }
};