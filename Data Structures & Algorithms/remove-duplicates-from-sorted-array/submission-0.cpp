class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        int previous = -101;
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] != previous) {
                nums[j++] = nums[i];
                previous = nums[i];
            } else {continue;}
        }
        return j;
    }
};