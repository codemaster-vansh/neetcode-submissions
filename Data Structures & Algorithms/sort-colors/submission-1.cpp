class Solution {
public:
    void sortColors(vector<int>& nums) {
        int arr[3] = {0};

        for (int i : nums) {
            arr[i]++;
        }

        int idx = 0;
        for (int num = 0;num < 3;num++) {
            for (int i = 0;i < arr[num];i++) {
                nums[idx] = num;
                idx++;
            }
        }
    }
};