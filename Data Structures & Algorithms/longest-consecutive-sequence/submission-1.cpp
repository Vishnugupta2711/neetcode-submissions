class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());

        int longest = 0;

        for (int x : seen) {

            // x is the beginning of a sequence
            if (seen.find(x - 1) == seen.end()) {

                int curr = x;
                int cnt = 1;

                while (seen.find(curr + 1) != seen.end()) {
                    curr++;
                    cnt++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};