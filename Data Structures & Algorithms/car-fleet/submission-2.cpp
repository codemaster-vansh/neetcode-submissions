class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<int> idxs(position.size());
        iota(idxs.begin(),idxs.end(),0);

        sort(idxs.begin(),idxs.end(),[&](int a, int b) {
            return position[a] > position[b];
        });

        int count = 0;
        stack<float> st1;
        for (int i = 0;i < idxs.size();i++) {
            float ttd = (float) (target - position[idxs[i]])/speed[idxs[i]];
            if (st1.empty() || st1.top() < ttd) {
                st1.push(ttd);
                count++;
            }
        }
        return count;
    }
};
