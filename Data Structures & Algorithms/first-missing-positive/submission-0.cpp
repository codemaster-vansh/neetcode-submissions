class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> check(n,false);

        for (int i : nums) {
            if (i > 0 && i <= n) {
                check[i - 1] = true;
            }
        }

        for (int i = 0;i < n;i++) {
            if (check[i] == false) return i + 1;
        }


        return n + 1;
    }
};