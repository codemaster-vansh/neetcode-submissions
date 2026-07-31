class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> unique;
        for (int i : nums) {
            if (i != val) unique.push_back(i);
        }

        for (int i = 0;i < unique.size();i++) {
            nums[i] = unique[i];
        }
        return unique.size();
    }
};