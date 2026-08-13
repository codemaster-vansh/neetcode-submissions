class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum1 = accumulate(weights.begin(),weights.end(),0);
        int max1 = *max_element(weights.begin(),weights.end());
        int lo = max1;
        int hi = sum1;

        auto canShip = [&](const vector<int>& weights, int days, int capacity) -> bool {
            int usedDays = 1;
            int currentLoad = 0;

            for (int w : weights) {
                if (w > capacity) return false;

                if (currentLoad + w > capacity) {
                    usedDays++;
                    currentLoad = 0;
                }
                currentLoad += w;
            }

            return usedDays <= days;
        };

        int ans = hi;

        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;

            if (canShip(weights,days,mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};