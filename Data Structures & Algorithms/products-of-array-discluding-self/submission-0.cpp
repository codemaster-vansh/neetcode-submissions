class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        vector<int> prefMul (n + 1, 1);
        vector<int> suffMul (n + 1, 1);

        for (int i = 0;i < n;i++) {
            prefMul[i + 1] = prefMul[i] * nums[i];
            suffMul[n - 1 - i] = suffMul[n - i] * nums[n - 1 - i];
        }

        for (int i = 0;i < n;i++) {
            result.push_back(prefMul[i] * suffMul[i + 1]);
        }
        return result;
    }   
};
