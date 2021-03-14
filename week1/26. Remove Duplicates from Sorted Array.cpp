class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 1. Pointer
        int count = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) count++;
            else nums[i-count] = nums[i];
        }
        return nums.size() - count;
        
        //2. STL
        // nums.erase(unique(nums.begin(), nums.end()), nums.end());
        // return nums.size();
    }
};