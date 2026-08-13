class Solution {
public:
    bool hours_taken(vector<int>& piles, int k, int h) {
        int count = 0;
        for (int i : piles) {
            count += (i + k - 1)/k;
        }
        return count <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int lo = 1, hi = *max_element(piles.begin(),piles.end());
        int ans = hi;
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if (hours_taken(piles,mid,h)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
