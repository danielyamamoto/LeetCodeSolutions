class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            mp.insert({nums[i], i});
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(target-nums[i]) != mp.end() && i!=mp[target-nums[i]]) {
                result.push_back(i);
                result.push_back(mp[target-nums[i]]);
                break;
            }
        }
        
        return result;
    }
};