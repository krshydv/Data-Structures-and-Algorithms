class RandomizedCollection {
public:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> mp;

    RandomizedCollection() {
    }
    
    bool insert(int val) {
        bool notPresent = mp[val].empty();
        nums.push_back(val);
        mp[val].insert(nums.size() - 1);
        return notPresent;
    }
    
    bool remove(int val) {
        if (mp[val].empty()) return false;

        int removeIndex = *mp[val].begin();
        mp[val].erase(removeIndex);

        int lastVal = nums.back();
        nums[removeIndex] = lastVal;

        mp[lastVal].insert(removeIndex);
        mp[lastVal].erase(nums.size() - 1);

        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        int idx = rand() % nums.size();
        return nums[idx];
    }
};