class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {\
        if (people.size() == 1) return 1;
        sort(people.begin(),people.end());

        int l = 0, r = people.size() - 1;
        int boats = 0;

        while (l < r) {
            if (people[l] + people[r] <= limit) {
                boats++;
                l++;
                r--;
            } else if (people[l] + people[r] > limit) {
                // Any hint for this? I am doing this weong
                r--;
                boats++;
            }
            if (l == r && people[l] <= limit) {
                boats++;
                break;
            }
        }
        return boats;
    }
};