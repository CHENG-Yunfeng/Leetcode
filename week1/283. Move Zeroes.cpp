class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j += 1;
            }
            else {
                count += 1;
            }
        }
        int idx = nums.size() - 1;
        for (int i = 0; i < count; ++i) {
            nums[idx] = 0;
            idx -= 1;
        }
    }
};