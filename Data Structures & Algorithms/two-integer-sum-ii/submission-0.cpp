class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int idx1 = 0, idx2 = numbers.size() - 1;
        while (idx1 < idx2) {
            int i = numbers[idx1] + numbers[idx2];
            if (i == target) {
                vector<int> result = {idx1+1,idx2+1};
                return result;
            } else if (i > target) {
                idx2--;
            } else {
                idx1++;
            }
        }
        return {idx1 + 1,idx2 + 1};
    }
};
