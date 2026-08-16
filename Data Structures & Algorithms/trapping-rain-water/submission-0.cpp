class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> prefixSum (n);
        vector<int> suffixSum (n);

        prefixSum[0] = height[0];suffixSum[n - 1] = height[n-1];

        for (int i = 1;i < n;i++) {
            prefixSum[i] = max(height[i],prefixSum[i - 1]);
            suffixSum[n - i - 1] = max(height[n - i - 1],suffixSum[n - i]);
        }

        int water_stored = 0;

        for (int i = 0;i < n;i++) {
            water_stored += min(prefixSum[i], suffixSum[i]) - height[i];
        }

        return water_stored;
    }
};
