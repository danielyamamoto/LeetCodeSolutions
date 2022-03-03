class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        
        std::sort(nums.begin(), nums.end());
        
        do {
            vector<int> tmp;
            for (int i = 0; i < nums.size(); i++) {
                tmp.push_back(nums[i]);
            }
            result.push_back(tmp);
        } while (next_permutation(nums.begin(), nums.end()));
    
        return result;
    }
};