class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        priority_queue<pair<int,int>> pq;
        for (const auto& p : freq) {
            pq.push({p.second, p.first});
        }

        vector<int> result;

        while (k-- && !pq.empty()) {
            auto top = pq.top();
            pq.pop();
            result.push_back(top.second);
        }

        return result;
    }
};
