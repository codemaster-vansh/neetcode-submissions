class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int max_vol = -1;

        while (l < r) {
            int vol = (r - l) * min(heights[l],heights[r]);
            if (vol > max_vol) {
                max_vol = vol;
            }

            if (heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return max_vol;
    }
};
