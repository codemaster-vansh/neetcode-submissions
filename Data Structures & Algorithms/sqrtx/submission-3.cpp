class Solution {
public:
    int mySqrt(int s) {
        if (s == 0) return 0;
        double x = s;
        double prev_x = -1;
        while (fabs(x - prev_x) > 1e-6) {
            prev_x = x;
            x = (x + s/x)/2.0;
        }
        return (int)x;
    }
};